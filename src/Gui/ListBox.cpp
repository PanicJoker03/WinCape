#include "Gui/GuiDefines.hpp"
#include "Gui/ListBox.hpp"
namespace cape{
namespace usr{
	//--------------------------------------------------------------------------
	//ListBox
	//--------------------------------------------------------------------------
	void ListBox::addString(CON_WSTR string) {
		SendMessage(handle(), ListBoxMessages::ADD_STRING, 0, (LPARAM)string);
	}
	int ListBox::count() {
		return SendMessage(handle(), ListBoxMessages::GET_COUNT, 0, 0);
	}

}}
