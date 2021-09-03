#Add
if app.BL_67_ATTR:
    import uiAttr67Add

#Find
    USE_TYPE_TUPLE = ("USE_CLEAN_SOCKET", "USE_CHANGE_ATTRIBUTE", "USE_ADD_ATTRIBUTE", "USE_ADD_ATTRIBUTE2", "USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET")

#Change
    if app.BL_67_ATTR:
		USE_TYPE_TUPLE = ("USE_CLEAN_SOCKET", "USE_CHANGE_ATTRIBUTE", "USE_CHANGE_ATTRIBUTE2", "USE_ADD_ATTRIBUTE", "USE_ADD_ATTRIBUTE2", "USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET")
	else:
		USE_TYPE_TUPLE = ("USE_CLEAN_SOCKET", "USE_CHANGE_ATTRIBUTE", "USE_ADD_ATTRIBUTE", "USE_ADD_ATTRIBUTE2", "USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET")

#Find if you have slot marking
                elif onTopWnd == player.ON_TOP_WND_SAFEBOX:
                    if player.IsAntiFlagBySlot(slotNumber, item.ANTIFLAG_SAFEBOX):
                        self.wndItem.SetUnusableSlotOnTopWnd(localIndex)
                    else:
                        self.wndItem.SetUsableSlotOnTopWnd(localIndex)

#Add
                elif app.BL_67_ATTR and onTopWnd == player.ON_TOP_WND_ATTR_67:
                    mark = (not self.interface.IsAttr67RegistItem() and not uiAttr67Add.Attr67AddWindow.CantAttachToAttrSlot(slotNumber, True)) or \
                        (self.interface.IsAttr67RegistItem() and not self.interface.IsAttr67SupportItem() and not uiAttr67Add.Attr67AddWindow.IsSupportItem(slotNumber))

                    if mark:
                        self.wndItem.SetUnusableSlotOnTopWnd(localIndex)
                    else:
                        self.wndItem.SetUsableSlotOnTopWnd(localIndex)

#Find if you have slot marking
                elif onTopWnd == player.ON_TOP_WND_SAFEBOX:
                    if player.IsAntiFlagBySlot(slotNumber, item.ANTIFLAG_SAFEBOX):
                        self.wndItem.SetUnusableSlotOnTopWnd(i)
                    else:
                        self.wndItem.SetUsableSlotOnTopWnd(i)

#Add
                elif app.BL_67_ATTR and onTopWnd == player.ON_TOP_WND_ATTR_67:
                    mark = (not self.interface.IsAttr67RegistItem() and not uiAttr67Add.Attr67AddWindow.CantAttachToAttrSlot(slotNumber, True)) or \
                        (self.interface.IsAttr67RegistItem() and not self.interface.IsAttr67SupportItem() and not uiAttr67Add.Attr67AddWindow.IsSupportItem(slotNumber))
                    
                    if mark:
                        self.wndItem.SetUnusableSlotOnTopWnd(i)
                    else:
                        self.wndItem.SetUsableSlotOnTopWnd(i)

#Find
			elif "USE_CHANGE_ATTRIBUTE" == useType:
				if self.__CanChangeItemAttrList(dstSlotPos):
					return True

#Add
			elif app.BL_67_ATTR and "USE_CHANGE_ATTRIBUTE2" == useType:
				if self.__CanChangeItemAttrList2(dstSlotPos):
					return True

#Find
	def __CanChangeItemAttrList(self, dstSlotPos):
		...

#Add
	if app.BL_67_ATTR:
        def __CanChangeItemAttrList2(self, dstSlotPos):
            return uiAttr67Add.Attr67AddWindow.CantAttachToAttrSlot(dstSlotPos, False)