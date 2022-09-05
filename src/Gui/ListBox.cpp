#include "Gui/GuiDefines.hpp"
#include "Gui/ListBox.hpp"
namespace cap{
namespace usr{
	//--------------------------------------------------------------------------
	//ListBox
	//--------------------------------------------------------------------------
	void ListBox::addString(WSTR_CON string) {
		SendMessage(handle(), ListBoxMessages::ADD_STRING, 0, (LPARAM)string);
	}
	int ListBox::count() {
		return SendMessage(handle(), ListBoxMessages::GET_COUNT, 0, 0);
	}

}}
