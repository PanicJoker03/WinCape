#include "Gui/ListBox.hpp"
namespace WinCape{
	namespace Gui{
		//-------------------------------------------------------------------------
		//ListBox
		//-------------------------------------------------------------------------
		void Gui::ListBox::addString(const TextChar* string) {
			SendMessage(handle(), ListBoxMessages::AddString, 0, (LPARAM)string);
		}
		int Gui::ListBox::count() {
			return SendMessage(handle(), ListBoxMessages::GetCount, 0, 0);
		}
	}
}
