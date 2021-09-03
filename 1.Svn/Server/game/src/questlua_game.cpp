//Find
	int game_web_mall(lua_State* L)
	{
		...
	}
	
///Add
#if defined(__BL_67_ATTR__)
	int game_open_67_attr(lua_State* L)
	{
		CQuestManager& q = CQuestManager::instance();
		LPCHARACTER ch = q.GetCurrentCharacterPtr();
		if (ch)
			ch->Open67Attr();
		
		return 0;
	}
#endif

//Find
			{ "open_web_mall",				game_web_mall					},

///Add
#if defined(__BL_67_ATTR__)
			{ "open_67_attr",				game_open_67_attr				},
#endif