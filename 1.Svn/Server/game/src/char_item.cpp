//Find in bool CHARACTER::CanHandleItem(bool bSkipCheckRefine, bool bSkipObserver)
	if (IsWarping())
		return false;
	
///Add
#if defined(__BL_67_ATTR__)
	if (Is67AttrOpen())
		return false;
#endif

//Find
				if (dwBoxVnum == 50033 && LC_IsYMIR())
				{
					...
				}

///Add Above
#if defined(__BL_67_ATTR__)
				switch (dwBoxVnum)
				{
				case POWERSHARD_CHEST:
					// The Powershard Chest can be purchased from Seon-Hae in exchange for 10 Skill Books.(From Wiki)
					// It can contain Powershards of any kind or a Skill Book.(From Wiki)
					// You can edit here for skill books(From black)
					if (number(1, 100) <= 30)
						AutoGiveItem(CItemVnumHelper::Get67MaterialVnum(number(0, gPlayerMaxLevel)));
					else
						ChatPacket(CHAT_TYPE_TALKING, LC_TEXT("아무것도 얻을 수 없었습니다."));
					item->SetCount(item->GetCount() - 1);
					return true;
				case ELEGANT_POWERSHARD_CHEST:
					if (number(1, 100) <= 60)
						AutoGiveItem(CItemVnumHelper::Get67MaterialVnum(number(0, gPlayerMaxLevel)));
					else
						ChatPacket(CHAT_TYPE_TALKING, LC_TEXT("아무것도 얻을 수 없었습니다."));
					item->SetCount(item->GetCount() - 1);
					return true;
				case LUCENT_POWERSHARD_CHEST:
					for (BYTE _i = 0; _i < 5; _i++)
						AutoGiveItem(CItemVnumHelper::Get67MaterialVnum(number(0, gPlayerMaxLevel)));
					item->SetCount(item->GetCount() - 1);
					return true;
				default:
					break;
				}
#endif

//Find
							case 71051 : // 진재가

///Change Whole Case
#if !defined(__BL_67_ATTR__)
							case 71051 : // 진재가
								{
									// 유럽, 싱가폴, 베트남 진재가 사용금지
									if (LC_IsEurope() || LC_IsSingapore() || LC_IsVietnam())
										return false;

									LPITEM item2;

									if (!IsValidItemPosition(DestCell) || !(item2 = GetInventoryItem(wDestCell)))
										return false;

									if (item2->IsExchanging() == true)
										return false;

									if (item2->GetAttributeSetIndex() == -1)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
										return false;
									}

									if (item2->AddRareAttribute() == true)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("성공적으로 속성이 추가 되었습니다"));

										int iAddedIdx = item2->GetRareAttrCount() + 4;
										char buf[21];
										snprintf(buf, sizeof(buf), "%u", item2->GetID());

										LogManager::instance().ItemLog(
												GetPlayerID(),
												item2->GetAttributeType(iAddedIdx),
												item2->GetAttributeValue(iAddedIdx),
												item->GetID(),
												"ADD_RARE_ATTR",
												buf,
												GetDesc()->GetHostName(),
												item->GetOriginalVnum());

										item->SetCount(item->GetCount() - 1);
									}
									else
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("더 이상 이 아이템으로 속성을 추가할 수 없습니다"));
									}
								}
								break;
#endif

//Find
							case 71052 : // 진재경

///Change Whole Case
#if !defined(__BL_67_ATTR__)
							case 71052 : // 진재경
								{
									// 유럽, 싱가폴, 베트남 진재가 사용금지
									if (LC_IsEurope() || LC_IsSingapore() || LC_IsVietnam())
										return false;

									LPITEM item2;

									if (!IsValidItemPosition(DestCell) || !(item2 = GetItem(DestCell)))
										return false;

									if (item2->IsExchanging() == true)
										return false;

									if (item2->GetAttributeSetIndex() == -1)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
										return false;
									}

									if (item2->ChangeRareAttribute() == true)
									{
										char buf[21];
										snprintf(buf, sizeof(buf), "%u", item2->GetID());
										LogManager::instance().ItemLog(this, item, "CHANGE_RARE_ATTR", buf);

										item->SetCount(item->GetCount() - 1);
									}
									else
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("변경 시킬 속성이 없습니다"));
									}
								}
								break;
#endif

//Find
							if (ITEM_COSTUME == item2->GetType())

///Change
#if defined(__BL_67_ATTR__)
							if (ITEM_COSTUME == item2->GetType() && item->GetSubType() != USE_CHANGE_ATTRIBUTE2)
#else
							if (ITEM_COSTUME == item2->GetType())
#endif

//Find
								case USE_ADD_ATTRIBUTE :

///Add Above
#if defined(__BL_67_ATTR__)
								case USE_CHANGE_ATTRIBUTE2:
									if (item2->GetAttributeSetIndex() == -1 || item2->GetRareAttrCount() == 0)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
										return false;
									}

									if (item2->IsEquipped())
										return false;

									if ((item->GetVnum() == SMALL_ORISON && number(1, 100) >= 10) == false 
										&& item2->ChangeRareAttribute() == true)
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("성공적으로 속성이 추가 되었습니다"));
									else
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("더 이상 이 아이템으로 속성을 추가할 수 없습니다"));

									item->SetCount(item->GetCount() - 1);
									break;
#endif

//Find in bool CHARACTER::UseItem(TItemPos Cell, TItemPos DestCell)
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_67_ATTR__)
			|| Is67AttrOpen()
#endif
		)
		
//Find in bool CHARACTER::UseItem(TItemPos Cell, TItemPos DestCell)
	if (item->GetVnum() == 50200 || item->GetVnum() == 71049)
	{
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
			
///Change
	if (item->GetVnum() == 50200 || item->GetVnum() == 71049)
	{
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_67_ATTR__)
			|| Is67AttrOpen()
#endif	
		)