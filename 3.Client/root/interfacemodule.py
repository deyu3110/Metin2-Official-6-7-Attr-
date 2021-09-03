#Add
if app.BL_67_ATTR:
	import uiAttr67Add

#Find
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)
			self.wndDragonSoulRefine.SetInventoryWindows(self.wndInventory, self.wndDragonSoul)
			self.wndInventory.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)

#Add
		if app.BL_67_ATTR:
			self.wndAttr67Add = uiAttr67Add.Attr67AddWindow()
			if app.WJ_ENABLE_TRADABLE_ICON:
				self.wndAttr67Add.BindInterface(self)
				self.wndAttr67Add.SetInven(self.wndInventory)
				self.wndInventory.BindWindow(self.wndAttr67Add)

#Find
        # ITEM_MALL
        if self.mallPageDlg:
            self.mallPageDlg.Destroy()
        # END_OF_ITEM_MALL

#Add
        if app.BL_67_ATTR:
            if self.wndAttr67Add:
                del self.wndAttr67Add

#Find
	def SelectMouseButtonEvent(self, dir, event):
		self.wndTaskBar.SelectMouseButtonEvent(dir, event)

#Add
	if app.BL_67_ATTR:
		def OpenAttr67AddDlg(self):
			if self.wndAttr67Add:
				self.wndAttr67Add.Show()

		if app.WJ_ENABLE_TRADABLE_ICON:
			def IsAttr67RegistItem(self):
				return self.wndAttr67Add and self.wndAttr67Add.RegistSlotIndex != -1

			def IsAttr67SupportItem(self):
				return self.wndAttr67Add and self.wndAttr67Add.SupportSlotIndex != -1