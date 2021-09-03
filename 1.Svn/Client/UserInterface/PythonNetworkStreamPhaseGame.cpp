//Find
			case HEADER_GC_MOTION:
				ret = RecvMotionPacket();
				break;

///Add
#if defined(__BL_67_ATTR__)
			case HEADER_GC_OPEN_67_ATTR:
				ret = Recv67AttrOpenPacket();
				break;
#endif

//Find
bool CPythonNetworkStream::SendCharacterPositionPacket(BYTE iPosition)
{
	...
}

///Add
#if defined(__BL_67_ATTR__)
bool CPythonNetworkStream::Send67AttrPacket(int iMaterialCount, int iSupportCount, int iSupportPos, int iItemPos)
{
	TPacketCG67Attr p =
	{
		static_cast<BYTE>(HEADER_CG_67_ATTR),
		static_cast<BYTE>(iMaterialCount),
		static_cast<BYTE>(iSupportCount),
		static_cast<short>(iSupportPos),
		static_cast<short>(iItemPos),
	};

	if (!Send(sizeof(p), &p))
	{
		Tracef("Send67AttrPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::Send67AttrClosePacket()
{
	TPacket67AttrOpenClose p;
	p.bHeader = HEADER_CG_CLOSE_67_ATTR;

	if (!Send(sizeof(p), &p))
	{
		Tracef("Send67AttrClosePacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::Recv67AttrOpenPacket()
{
	TPacket67AttrOpenClose p;

	if (!Recv(sizeof(p), &p))
		return false;

	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OpenAttr67AddDlg", Py_BuildValue("()"));

	return true;
}
#endif