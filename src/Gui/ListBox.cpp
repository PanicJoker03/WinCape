#include "Gui/GuiDefines.hpp"
#include "Gui/ListBox.hpp"
namespace WinCape{
namespace Gui{
	//--------------------------------------------------------------------------
	//ListBox
	//--------------------------------------------------------------------------
	void ListBox::addString(const wchar_t* string) {
		SendMessage(handle(), ListBoxMessages::ADD_STRING, 0, (LPARAM)string);
	}
	int ListBox::count() {
		return SendMessage(handle(), ListBoxMessages::GET_COUNT, 0, 0);
	}

}}
