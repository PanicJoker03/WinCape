#include "Ui/UiDefines.h"
#include "Ui/ListBox.h"
namespace w_cape{
namespace ui{
	//--------------------------------------------------------------------------
	//ListBox
	//--------------------------------------------------------------------------
	void ListBox::addString(WSTR_CON string) {
		SendMessage(handle(), ListBoxMessages::ADD_STR, 0, (LPARAM)string);
	}
	int ListBox::count() {
		return SendMessage(handle(), ListBoxMessages::GET_CON, 0, 0);
	}

}}
