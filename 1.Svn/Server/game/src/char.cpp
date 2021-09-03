//Find
	m_pGuild = NULL;
	
///Add
#if defined(__BL_67_ATTR__)
	b67Attr = false;
#endif

//Find in void CHARACTER::OnClick(LPCHARACTER pkChrCauser)
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen())

///Change
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen()
#if defined(__BL_67_ATTR__)
						|| Is67AttrOpen()
#endif
					)

//Find in void CHARACTER::OnClick(LPCHARACTER pkChrCauser)
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen())

///Change
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen()
#if defined(__BL_67_ATTR__)
						|| pkChrCauser->Is67AttrOpen()
#endif	
					)

//Find in void CHARACTER::OnClick(LPCHARACTER pkChrCauser)
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen()))

///Change
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen())
#if defined(__BL_67_ATTR__)
						|| Is67AttrOpen()
#endif
					)

//Find in bool CHARACTER::IsHack(bool bSendMsg, bool bCheckShopOwner, int limittime)
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_67_ATTR__)
			|| Is67AttrOpen()
#endif
		)
		
//Find in bool CHARACTER::IsHack(bool bSendMsg, bool bCheckShopOwner, int limittime)
	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())
		
///Change
	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| Is67AttrOpen()
#endif
	)

//Find in bool CHARACTER::CanWarp() const
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())
			
///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_67_ATTR__)
			|| Is67AttrOpen()
#endif
		)
		
//Find
BYTE CHARACTER::GetChatCounter() const
{
	...
}

///Add
#if defined(__BL_67_ATTR__)
void CHARACTER::Open67Attr()
{
	LPDESC d = GetDesc();
	if (!d)
		return;
	
	if (GetExchange() || IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen() || Is67AttrOpen())
	{
		ChatPacket(CHAT_TYPE_INFO, "You have to close other windows.");
		return;
	}

	Set67Attr(true);

	TPacket67AttrOpenClose p;
	p.bHeader = HEADER_GC_OPEN_67_ATTR;
	d->Packet(&p, sizeof(p));
}
#endif