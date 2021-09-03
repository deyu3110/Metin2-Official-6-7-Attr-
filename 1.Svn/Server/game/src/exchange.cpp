//Find in bool CHARACTER::ExchangeStart(LPCHARACTER victim)
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen() )
		
///Change
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| Is67AttrOpen()
#endif
	)

//Find in bool CHARACTER::ExchangeStart(LPCHARACTER victim)
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen() )

///Change
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| victim->Is67AttrOpen()
#endif
	)