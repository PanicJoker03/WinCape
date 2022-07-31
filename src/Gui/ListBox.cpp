#include "Gui/ListBox.hpp"
namespace WinCape::Gui
{
	//--------------------------------------------------------------------------
	//ListBox
	//--------------------------------------------------------------------------
	void ListBox::addString(const wchar_t* string) {
		SendMessage(handle(), ListBoxMessages::AddString, 0, (LPARAM)string);
	}
	int ListBox::count() {
		return SendMessage(handle(), ListBoxMessages::GetCount, 0, 0);
	}

}
