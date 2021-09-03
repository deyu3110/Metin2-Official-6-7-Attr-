//Find
PyObject* netDisconnect(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_67_ATTR__)
PyObject* netSend67AttrPacket(PyObject* poSelf, PyObject* poArgs)
{
	int iMaterialCount;
	if (!PyTuple_GetInteger(poArgs, 0, &iMaterialCount))
		return Py_BuildException();

	int iSupportCount;
	if (!PyTuple_GetInteger(poArgs, 1, &iSupportCount))
		return Py_BuildException();

	int iSupportPos;
	if (!PyTuple_GetInteger(poArgs, 2, &iSupportPos))
		return Py_BuildException();

	int iItemPos;
	if (!PyTuple_GetInteger(poArgs, 3, &iItemPos))
		return Py_BuildException();

	CPythonNetworkStream::Instance().Send67AttrPacket(iMaterialCount, iSupportCount, iSupportPos, iItemPos);
	return Py_BuildNone();
}

PyObject* netSend67AttrClosePacket(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().Send67AttrClosePacket();
	return Py_BuildNone();
}
#endif

//Find
		{ "RegisterErrorLog",						netRegisterErrorLog,						METH_VARARGS },
		
///Add
#if defined(__BL_67_ATTR__)
		{ "Send67AttrPacket",						netSend67AttrPacket,						METH_VARARGS },
		{ "Send67AttrClosePacket",					netSend67AttrClosePacket,					METH_VARARGS },
#endif