import uiCommon
import uiToolTip
import app
import item
import net
import player
import ui
import mouseModule
import uiScriptLocale
import localeInfo

# BL_67_ATTR


class Attr67AddWindow(ui.ScriptWindow):
    RANGE_MAX = 500
    MATERIAL_MAX_COUNT = 10
    SUCCESS_PER_MATERIAL = 2.0
    SUPPORT_MAX_COUNT = 5
    
    SUPPORT_DICT = {
        72064: 1.0,
        72065: 2.0,
        72066: 4.0,
        72067: 10.0,
    }

    Attr67ToolTipList = [
        localeInfo.ATTR_6TH_7TH_DESC1,
        localeInfo.ATTR_6TH_7TH_DESC2,
        localeInfo.ATTR_6TH_7TH_DESC3,
        # localeInfo.ATTR_6TH_7TH_DESC4,
    ]

    def __init__(self):
        super(Attr67AddWindow, self).__init__()
        self.isLoaded = False
        self.StartPosX = 0
        self.StartPosY = 0
        self.pop = None
        self.tooltipitem = uiToolTip.ItemToolTip()
        self.MaterialSlotIndex = -1
        self.SupportSlotIndex = -1
        self.RegistSlotIndex = -1

    def __del__(self):
        super(Attr67AddWindow, self).__del__()
        self.QuestionButton = None
        self.QuestionToolTip = None
        self.MaterialCountText = None
        self.MaterialSlot = None
        self.SupportCountText = None
        self.SupportSlot = None
        self.RegistSlot = None
        self.TotalSuccessText = None
        self.pop = None
        self.tooltipitem = None
        self.MaterialSlotIndex = -1
        self.SupportSlotIndex = -1
        self.RegistSlotIndex = -1

    def __LoadWindow(self):
        if self.isLoaded:
            return

        self.isLoaded = True

        # script
        try:
            self.__LoadScript("UIScript/Attr67AddDialog.py")

        except:
            import exception
            exception.Abort("Attr67AddWindow.__LoadWindow.__LoadScript")

        # object
        try:
            self.__BindObject()
        except:
            import exception
            exception.Abort("Attr67AddWindow.__LoadWindow.__BindObject")

        # event
        try:
            self.__BindEvent()
        except:
            import exception
            exception.Abort("Attr67AddWindow.__LoadWindow.__BindEvent")

    def __LoadScript(self, fileName):
        pyScrLoader = ui.PythonScriptLoader()
        pyScrLoader.LoadScriptFile(self, fileName)

    def __BindObject(self):
        self.QuestionButton = self.GetChild("question_button")
        self.QuestionToolTip = self.__CreateGameTypeToolTip(Attr67AddWindow.Attr67ToolTipList)
        self.QuestionToolTip.SetTop()
        self.QuestionButton.SetToolTipWindow(self.QuestionToolTip)
        self.MaterialCountText = self.GetChild("material_slot_count_text")
        self.MaterialSlot = self.GetChild("material_slot")
        self.SupportCountText = self.GetChild("support_slot_count_text")
        self.SupportSlot = self.GetChild("support_slot")
        self.RegistSlot = self.GetChild("regist_slot")
        self.TotalSuccessText = self.GetChild("TotalSuccessText")

    def __BindEvent(self):
        self.GetChild("board").SetCloseEvent(ui.__mem_func__(self.Close))
        self.GetChild("attr_add_button").SetEvent(ui.__mem_func__(self.__ClickAttrAddButton))
        self.GetChild("material_slot_arrow_up_button").SetEvent(ui.__mem_func__(self.ClickMaterialButton), True)
        self.GetChild("material_slot_arrow_down_button").SetEvent(ui.__mem_func__(self.ClickMaterialButton), False)
        self.GetChild("support_slot_arrow_up_button").SetEvent(ui.__mem_func__(self.ClickSuppotButton), True)
        self.GetChild("support_slot_arrow_down_button").SetEvent(ui.__mem_func__(self.ClickSuppotButton), False)

        self.RegistSlot.SetOverInItemEvent(ui.__mem_func__(self.OverInRegistSlot))
        self.RegistSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
        self.RegistSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.SelectItemRegistSlot))
        self.RegistSlot.SetUseSlotEvent(ui.__mem_func__(self.SelectItemRegistSlot))
        self.RegistSlot.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptyRegistSlot))
        self.RegistSlot.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemRegistSlot))

        self.SupportSlot.SetOverInItemEvent(ui.__mem_func__(self.OverInSupportSlot))
        self.SupportSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
        self.SupportSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.SelectItemSupportSlot))
        self.SupportSlot.SetUseSlotEvent(ui.__mem_func__(self.SelectItemSupportSlot))
        self.SupportSlot.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySupportSlot))
        self.SupportSlot.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSupportSlot))

        self.MaterialSlot.SetOverInItemEvent(ui.__mem_func__(self.OverInMaterialSlot))
        self.MaterialSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))

    def __CreateGameTypeToolTip(self, descList):
        toolTip = uiToolTip.ToolTip()

        for desc in descList:
            toolTip.AutoAppendTextLine(desc)

        toolTip.AlignHorizonalCenter()
        toolTip.SetTop()
        return toolTip
    
    @staticmethod
    def CantAttachToAttrSlot(inven_slot, bAdd):
        dstItemVNum = player.GetItemIndex(inven_slot)
        if dstItemVNum == 0:
            return False

        item.SelectItem(dstItemVNum)

        if not item.GetItemType() in (item.ITEM_TYPE_WEAPON, item.ITEM_TYPE_ARMOR, item.ITEM_TYPE_COSTUME):
            return False
            
        attrCount = 0
        for i in range(player.ATTRIBUTE_SLOT_MAX_NUM):
            attr, val = player.GetItemAttribute(inven_slot, i)
            if attr:
                attrCount += 1

        return (5 <= attrCount <= 6) if bAdd else (6 <= attrCount)

    def SelectItemRegistSlot(self, slot_index):
        if mouseModule.mouseController.isAttached():
            return

        if self.pop and self.pop.IsShow():
            return

        self.__ClearData()

        mouseModule.mouseController.DeattachObject()

    def SelectEmptyRegistSlot(self, slot_index):
        if not mouseModule.mouseController.isAttached():
            return

        attachedSlotType = mouseModule.mouseController.GetAttachedType()
        attachedSlotPos = mouseModule.mouseController.GetAttachedSlotNumber()
        attachedItemVnum = player.GetItemIndex(attachedSlotPos)
        mouseModule.mouseController.DeattachObject()

        if player.SLOT_TYPE_INVENTORY != attachedSlotType:
            return

        if player.IsEquipmentSlot(attachedSlotPos):
            return

        if not Attr67AddWindow.CantAttachToAttrSlot(attachedSlotPos, True):
            return

        item.SelectItem(attachedItemVnum)

        level_limit = 0
        for i in range(item.LIMIT_MAX_NUM):
            (limitType, limitValue) = item.GetLimit(i)
            if item.LIMIT_LEVEL == limitType:
                level_limit = limitValue

        MaterialVnum = self.GetMaterialVnum(level_limit)
        self.MaterialSlot.SetItemSlot(slot_index, MaterialVnum)
        self.MaterialSlot.RefreshSlot()
        self.MaterialCountText.SetText("1")
        self.MaterialSlotIndex = MaterialVnum

        self.RegistSlot.SetItemSlot(slot_index, attachedItemVnum)
        self.RegistSlot.RefreshSlot()
        self.RegistSlotIndex = attachedSlotPos

        self.__CalculateTotalSuccessPer()
    
    def SelectItemSupportSlot(self, slot_index):
        if mouseModule.mouseController.isAttached():
            return

        if self.pop and self.pop.IsShow():
            return

        self.__ClearSupportSlot()
        self.__CalculateTotalSuccessPer()

        mouseModule.mouseController.DeattachObject()

    def SelectEmptySupportSlot(self, slot_index):
        if not mouseModule.mouseController.isAttached():
            return

        attachedSlotType = mouseModule.mouseController.GetAttachedType()
        attachedSlotPos = mouseModule.mouseController.GetAttachedSlotNumber()
        attachedItemVnum = player.GetItemIndex(attachedSlotPos)
        mouseModule.mouseController.DeattachObject()

        if self.RegistSlotIndex == -1:
            return

        if player.SLOT_TYPE_INVENTORY != attachedSlotType:
            return

        if attachedItemVnum not in Attr67AddWindow.SUPPORT_DICT:
            return

        self.SupportCountText.SetText("1")
        self.SupportSlot.SetItemSlot(slot_index, attachedItemVnum)
        self.SupportSlot.RefreshSlot()
        self.SupportSlotIndex = attachedSlotPos

        self.__CalculateTotalSuccessPer()

    def GetMaterialVnum(self, item_level):
        if item_level >= 0 and item_level <= 29:
            return 39070

        if item_level >= 31 and item_level <= 39:
            return 39071

        if item_level >= 40 and item_level <= 49:
            return 39072

        if item_level >= 50 and item_level <= 59:
            return 39073

        if item_level >= 60 and item_level <= 74:
            return 39074

        if item_level >= 76 and item_level <= 89:
            return 39075

        if item_level >= 90 and item_level <= 104:
            return 39076

        if item_level >= 106 and item_level <= 120:
            return 39077

        if item_level >= 121 and item_level <= 150:
            return 39081

        if item_level == 30:
            return 39078

        if item_level == 75:
            return 39079

        if item_level == 105:
            return 39080

        return 0

    def __CalculateTotalSuccessPer(self):
        material_count = int(self.MaterialCountText.GetText())
        percent = material_count * Attr67AddWindow.SUCCESS_PER_MATERIAL
        
        if self.SupportSlotIndex != -1:
            support_vnum = player.GetItemIndex(self.SupportSlotIndex)
            if support_vnum:
                SUCCESS_PER_SUPPORT = Attr67AddWindow.SUPPORT_DICT.get(support_vnum, 0.0)
                support_count = int(self.SupportCountText.GetText())
                percent += support_count * SUCCESS_PER_SUPPORT

        self.TotalSuccessText.SetText(localeInfo.ATTR_6TH_7TH_TOTAL_SUCCESS_PERCENT % percent)
        
        if app.WJ_ENABLE_TRADABLE_ICON:
            self.RefreshLockedSlot()

    def __ClearData(self):
        self.__ClearRegistSlot()
        self.__ClearSupportSlot()
        self.__ClearMaterialSlot()
        self.__CalculateTotalSuccessPer()

    def __ClearRegistSlot(self):
        self.RegistSlot.SetItemSlot(0, 0)
        self.RegistSlot.RefreshSlot()
        self.RegistSlotIndex = -1

    def __ClearMaterialSlot(self):
        self.MaterialCountText.SetText("0")
        self.MaterialSlot.SetItemSlot(0, 0)
        self.MaterialSlot.RefreshSlot()
        self.MaterialSlotIndex = -1

    def __ClearSupportSlot(self):
        self.SupportCountText.SetText("0")
        self.SupportSlot.SetItemSlot(0, 0)
        self.SupportSlot.RefreshSlot()
        self.SupportSlotIndex = -1

    def __ClickAttrAddButton(self):
        self.OnCloseEvent()

        if self.RegistSlotIndex == -1:
            return

        popup = uiCommon.QuestionDialog2()
        popup.SetText1(localeInfo.ATTR_6TH_7TH_ADD_QUESTION1)
        popup.SetText2(localeInfo.ATTR_6TH_7TH_ADD_QUESTION2)
        popup.SetAcceptEvent(self.__SendAttr67AddPacket)
        popup.SetCancelEvent(self.OnCloseEvent)
        popup.Open()
        self.pop = popup

    def __SendAttr67AddPacket(self):
        if self.RegistSlotIndex != -1:
            material_count = int(self.MaterialCountText.GetText())
            support_count = int(self.SupportCountText.GetText())

            net.Send67AttrPacket(material_count, support_count, self.SupportSlotIndex, self.RegistSlotIndex)
        
        self.Close()

    def ClickMaterialButton(self, is_up_button_click):
        if self.MaterialSlotIndex == -1:
            return

        if self.pop and self.pop.IsShow():
            return

        material_count = int(self.MaterialCountText.GetText())

        if is_up_button_click and material_count >= Attr67AddWindow.MATERIAL_MAX_COUNT:
            return

        if not is_up_button_click and material_count <= 1:
            return

        material_count += 1 if is_up_button_click else -1
        self.MaterialCountText.SetText(str(material_count))

        self.__CalculateTotalSuccessPer()

    def ClickSuppotButton(self, is_up_button_click):
        if self.SupportSlotIndex == -1:
            return

        if self.pop and self.pop.IsShow():
            return

        support_count = int(self.SupportCountText.GetText())

        if is_up_button_click and support_count >= Attr67AddWindow.SUPPORT_MAX_COUNT:
            return

        if not is_up_button_click and support_count <= 1:
            return

        support_count += 1 if is_up_button_click else -1
        self.SupportCountText.SetText(str(support_count))

        self.__CalculateTotalSuccessPer()

    def OverInMaterialSlot(self, slot_index):
        if not self.tooltipitem:
            return

        if self.MaterialSlotIndex == -1:
            return

        self.tooltipitem.AddItemData(self.MaterialSlotIndex, 0, 0)

    def OverInRegistSlot(self, slot_index):
        if not self.tooltipitem:
            return

        if self.RegistSlotIndex == -1:
            return

        self.tooltipitem.SetInventoryItem(self.RegistSlotIndex, player.INVENTORY)

    def OverInSupportSlot(self, slot_index):
        if not self.tooltipitem:
            return

        if self.SupportSlotIndex == -1:
            return

        self.tooltipitem.SetInventoryItem(self.SupportSlotIndex, player.INVENTORY)

    def OverOutItem(self):
        if self.tooltipitem:
            self.tooltipitem.HideToolTip()
            self.tooltipitem.ClearToolTip()

    def RangeCheck(self):
        (x, y, z) = player.GetMainCharacterPosition()
        if abs(x - self.StartPosX) > Attr67AddWindow.RANGE_MAX or abs(y - self.StartPosY) > Attr67AddWindow.RANGE_MAX:
            self.Close()

    def OnUpdate(self):
        self.RangeCheck()
    
    def OnCloseEvent(self):
        if self.pop != None:
            self.pop.Close()
            self.pop = None
    
    def Show(self):
        if self.IsShow():
            return

        (self.StartPosX, self.StartPosY, z) = player.GetMainCharacterPosition()
        self.__LoadWindow()
        self.__ClearData()
        self.SetCenterPosition()
        self.SetTop()
        self.OnTop()

        super(Attr67AddWindow, self).Show()
    
    def Close(self):
        self.OnCloseEvent()
        self.Hide()
        self.__ClearData()
        net.Send67AttrClosePacket()

        if app.WJ_ENABLE_TRADABLE_ICON:
            self.interface.SetOnTopWindow(player.ON_TOP_WND_NONE)
            self.interface.RefreshMarkInventoryBag()

    def OnPressEscapeKey(self):
        self.Close()
        return True

    if app.WJ_ENABLE_TRADABLE_ICON:
        
        @staticmethod
        def IsSupportItem(inven_slot):
            dstItemVNum = player.GetItemIndex(inven_slot)
            if dstItemVNum == 0:
                return False

            return dstItemVNum in Attr67AddWindow.SUPPORT_DICT
        
        def RefreshLockedSlot(self):
            if self.inven == None:
                return

            for i in range(player.INVENTORY_PAGE_SIZE):
                self.inven.wndItem.SetCanMouseEventSlot(i)
            
            for i in (self.SupportSlotIndex, self.RegistSlotIndex):
                if i != -1:
                    itemInvenPage = i / player.INVENTORY_PAGE_SIZE
                    localSlotPos = i - (itemInvenPage * player.INVENTORY_PAGE_SIZE)
                    if self.inven.GetInventoryPageIndex() == itemInvenPage:
                        self.inven.wndItem.SetCantMouseEventSlot(localSlotPos)
                        
            self.inven.wndItem.RefreshSlot()
            self.inven.RefreshMarkSlots()
        
        def BindInterface(self, interface):
            from _weakref import proxy
            self.interface = proxy(interface)

        def SetInven(self, inven):
            from _weakref import proxy
            self.inven = proxy(inven)
        
        def OnTop(self):
            if self.tooltipitem:
                self.tooltipitem.SetTop()

            if app.WJ_ENABLE_TRADABLE_ICON and self.interface:
                self.interface.SetOnTopWindow(player.ON_TOP_WND_ATTR_67)
                self.interface.RefreshMarkInventoryBag()
