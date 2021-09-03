//Find
	Set(HEADER_CG_GUILD, sizeof(TPacketCGGuild), "Guild", true);
	
///Add
#if defined(__BL_67_ATTR__)
	Set(HEADER_CG_67_ATTR, sizeof(TPacketCG67Attr), "67Attr", true);
	Set(HEADER_CG_CLOSE_67_ATTR, sizeof(TPacket67AttrOpenClose), "67AttrClose", true);
#endif