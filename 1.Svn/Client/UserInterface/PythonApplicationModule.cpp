//Find

#ifdef ENABLE_ENERGY_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_ENERGY_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_ENERGY_SYSTEM",	0);
#endif

///Add
#if defined(__BL_67_ATTR__)
	PyModule_AddIntConstant(poModule, "BL_67_ATTR", true);
#ifndef WJ_ENABLE_TRADABLE_ICON
	PyModule_AddIntConstant(poModule, "WJ_ENABLE_TRADABLE_ICON", 0);
#endif
#else
	PyModule_AddIntConstant(poModule, "BL_67_ATTR", false);
#endif