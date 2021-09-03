//Find in bool CShopManager::StartShopping(LPCHARACTER pkChr, LPCHARACTER pkChrShopKeeper, int iShopVnum)
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen())

///Change
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| pkChr->Is67AttrOpen()
#endif
	)