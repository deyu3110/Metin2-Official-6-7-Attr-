//Find
		bool SendSelectItemPacket(DWORD dwItemPos);

///Add
#if defined(__BL_67_ATTR__)
		bool Send67AttrPacket(int iMaterialCount, int iSupportCount, int iSupportPos, int iItemPos);
		bool Send67AttrClosePacket();
		bool Recv67AttrOpenPacket();
#endif