//Find
			Set(HEADER_GC_WHISPER,				CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCWhisper), STATIC_SIZE_PACKET));

///Add
#if defined(__BL_67_ATTR__)
			Set(HEADER_GC_OPEN_67_ATTR, 		CNetworkPacketHeaderMap::TPacketType(sizeof(TPacket67AttrOpenClose), STATIC_SIZE_PACKET));
#endif