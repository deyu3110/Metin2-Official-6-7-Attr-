//Find in void CInputDB::SafeboxLoad(LPDESC d, const char * c_pData)
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_67_ATTR__)
		|| ch->Is67AttrOpen()
#endif
	)