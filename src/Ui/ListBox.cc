#include "Ui/UiDefines.h"
#include "Ui/ListBox.h"
namespace w_cape{
namespace ui{
	//--------------------------------------------------------------------------
	//ListBox
	//--------------------------------------------------------------------------
	void ListBox::addString(WCH_STR_CONST string) {
		SendMessage(handle(), ListBoxMessages::ADD_STR, 0, (LPARAM)string);
	}
	int ListBox::count() const {
		return SendMessage(handle(), ListBoxMessages::GET_CONT, 0, 0);
	}

}}
