#Find
	SPECIAL_POSITIVE_COLOR2 = grp.GenerateColor(0.8824, 0.9804, 0.8824, 1.0)

#Add
	if app.BL_67_ATTR:
		ATTR_6TH_7TH_COLOR = -102

#Find in def __GetAttributeColor(self, index, value):
			if index >= 5:
				return self.SPECIAL_POSITIVE_COLOR2

#Change
			if index >= 5:
				if app.BL_67_ATTR:
					return self.ATTR_6TH_7TH_COLOR
				else:
					return self.SPECIAL_POSITIVE_COLOR2

#Add in same class
	if app.BL_67_ATTR:
		def AppendAttribute6th7thPossibility(self, attrSlot):
			if attrSlot == 0:
				return

			count = 0
			for i in range(player.ATTRIBUTE_SLOT_MAX_NUM):
				type = attrSlot[i][0]
				value = attrSlot[i][1]

				if 0 == type or 0 == value:
					continue

				count += 1

			if (5 <= count <= 6):
				self.AppendTextLine(localeInfo.ATTR_6TH_7TH_POSSIBILITY, self.ATTR_6TH_7TH_COLOR)

#Find in if item.ITEM_TYPE_WEAPON == itemType:
			self.__AppendAttributeInformation(attrSlot)

#Add
			if app.BL_67_ATTR:
				self.AppendAttribute6th7thPossibility(attrSlot)

#Find in elif item.ITEM_TYPE_ARMOR == itemType:
			self.__AppendAttributeInformation(attrSlot)

#Add
			if app.BL_67_ATTR:
				self.AppendAttribute6th7thPossibility(attrSlot)

#Find in elif 0 != isCostumeItem:
			self.__AppendAttributeInformation(attrSlot)

#Add
			if app.BL_67_ATTR:
				self.AppendAttribute6th7thPossibility(attrSlot)