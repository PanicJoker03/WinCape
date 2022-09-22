#include "Ui/UiDefines.hpp"
#include "Ui/ListBox.hpp"
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
