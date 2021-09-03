///Add
#include "service.h"

//Find
	static	const bool	IsLovePendant(DWORD vnum)		{ return 71145 == vnum; }

///Add
#if defined(__BL_67_ATTR__)
	static DWORD Get67MaterialVnum(const int iLevelLimit)
	{
		// https://en-wiki.metin2.gameforge.com/index.php/Bonuses#:~:text=50%25-,powershards,-Image

		if (iLevelLimit >= 0 && iLevelLimit <= 29)
			return 39070;

		if (iLevelLimit >= 31 && iLevelLimit <= 39)
			return 39071;

		if (iLevelLimit >= 40 && iLevelLimit <= 49)
			return 39072;

		if (iLevelLimit >= 50 && iLevelLimit <= 59)
			return 39073;

		if (iLevelLimit >= 60 && iLevelLimit <= 74)
			return 39074;

		if (iLevelLimit >= 76 && iLevelLimit <= 89)
			return 39075;

		if (iLevelLimit >= 90 && iLevelLimit <= 104)
			return 39076;

		if (iLevelLimit >= 106 && iLevelLimit <= 120)
			return 39077;

		if (iLevelLimit >= 121 && iLevelLimit <= 150) // Edit for Yohara
			return 39081;

		if (iLevelLimit == 30)
			return 39078;

		if (iLevelLimit == 75)
			return 39079;

		if (iLevelLimit == 105)
			return 39080;

		return 0;
	}
#endif