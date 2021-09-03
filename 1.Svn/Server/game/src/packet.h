//Find
	HEADER_CG_STATE_CHECKER					= 206,
	
///Add
#if defined(__BL_67_ATTR__)
	HEADER_CG_67_ATTR 						= 208,
	HEADER_CG_CLOSE_67_ATTR 				= 209,
#endif

//Find
	HEADER_GC_RESPOND_CHANNELSTATUS			= 210,
	
///Add
#if defined(__BL_67_ATTR__)
	HEADER_GC_OPEN_67_ATTR 					= 219,
#endif

//Find
typedef struct
{
	...
} TPacketGCTargetDelete;

///Add
#if defined(__BL_67_ATTR__)
typedef struct command_67_attr
{
	BYTE			bHeader;
	BYTE			bMaterialCount;
	BYTE			bSupportCount;
	short			sSupportPos;
	short			sItemPos;
} TPacketCG67Attr;

typedef struct command_67_attr_open_close
{
	BYTE			bHeader;
} TPacket67AttrOpenClose;
#endif