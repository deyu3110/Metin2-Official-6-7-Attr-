//Find in void CInputMain::Exchange(LPCHARACTER ch, const char * data)
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_67_ATTR__)
						|| ch->Is67AttrOpen()
#endif
					)

//Find in int CInputMain::MyShop(LPCHARACTER ch, const char * c_pData, size_t uiBytes)
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| ch->Is67AttrOpen()
#endif
	)
	
///Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	...
}

///Add
#if defined(__BL_67_ATTR__)
#include "../../common/VnumHelper.h"

void CInputMain::Attr67(LPCHARACTER ch, const char* c_pData)
{
	const TPacketCG67Attr* p = reinterpret_cast<const TPacketCG67Attr*>(c_pData);
	
	if (ch->IsDead())
		return;
	
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetMyShop() || ch->GetShopOwner() || ch->IsCubeOpen())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "You have to close other windows.");
		return;
	}
	
	const LPITEM item = ch->GetInventoryItem(p->sItemPos);
	if (!item)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "There is no item.");
		return;
	}

	switch (item->GetType())
	{
	case ITEM_WEAPON:
	case ITEM_ARMOR:
	case ITEM_COSTUME:
		break;
	default:
		ch->ChatPacket(CHAT_TYPE_INFO, "The item type is not suitable for 6-7 attr.");
		return;
	}

	if (item->IsEquipped())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "You cannot add a bonus to a equipped item.");
		return;
	}

	if (item->IsExchanging())
		return;

	const int norm_attr_count = item->GetAttributeCount();
	const int rare_attr_count = item->GetRareAttrCount();
	const int attr_set_index = item->GetAttributeSetIndex();

	if (attr_set_index == -1 || norm_attr_count < 5 || rare_attr_count >= 2)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "This item is not suitable for 6-7 attr.");
		return;
	}

	enum
	{
		SUCCESS_PER_MATERIAL = 2,
		MATERIAL_MAX_COUNT = 10,
		SUPPORT_MAX_COUNT = 5,
	};

	if (p->bMaterialCount > MATERIAL_MAX_COUNT || p->bSupportCount > SUPPORT_MAX_COUNT)
		return;

	const DWORD dwMaterialVnum = CItemVnumHelper::Get67MaterialVnum(item->GetLevelLimit());
	if (dwMaterialVnum == 0 || p->bMaterialCount < 1 
		|| ch->CountSpecifyItem(dwMaterialVnum) < p->bMaterialCount)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "You don't have enough material item.");
		return;
	}
	
	BYTE success = SUCCESS_PER_MATERIAL * p->bMaterialCount;
	
	if (p->sSupportPos != -1)
	{
		const LPITEM support_item = ch->GetInventoryItem(p->sSupportPos);
		if (support_item)
		{
			if (support_item->GetCount() < p->bSupportCount)
			{
				ch->ChatPacket(CHAT_TYPE_INFO, "You don't have enough support item.");
				return;
			}

			BYTE uSupportSuccess = 0;
			switch (support_item->GetVnum())
			{
			case 72064:
				uSupportSuccess = 1;
				break;
			case 72065:
				uSupportSuccess = 2;
				break;
			case 72066:
				uSupportSuccess = 4;
				break;
			case 72067:
				uSupportSuccess = 10;
				break;
			default:
				ch->ChatPacket(CHAT_TYPE_INFO, "The support item is inappropriate.");
				return;
			}

			success += uSupportSuccess * p->bSupportCount;
			support_item->SetCount(support_item->GetCount() - p->bSupportCount);
		}
	}

	ch->RemoveSpecifyItem(dwMaterialVnum, p->bMaterialCount);
	
	const bool bAdded = (number(1, 100) <= success && item->AddRareAttribute());
	ch->ChatPacket(CHAT_TYPE_INFO, "%s!", bAdded ? "Success" : "Failed");
}

void CInputMain::Attr67Close(LPCHARACTER ch, const char* c_pData)
{
	ch->Set67Attr(false);
}
#endif

//Find in void CInputMain::Refine(LPCHARACTER ch, const char* c_pData)
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| ch->Is67AttrOpen()
#endif
	)
	
//Find
		case HEADER_CG_QUEST_CONFIRM:
			QuestConfirm(ch, c_pData);
			break;
			
///Add
#if defined(__BL_67_ATTR__)
		case HEADER_CG_67_ATTR:
			Attr67(ch, c_pData);
			break;
			
		case HEADER_CG_CLOSE_67_ATTR:
			Attr67Close(ch, c_pData);
			break;
#endif