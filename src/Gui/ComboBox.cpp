#include "Gui/Combobox.hpp"
namespace WinCape{
	namespace Gui {
		//-------------------------------------------------------------------------
		//ComboBox
		//-------------------------------------------------------------------------
		void Gui::ComboBox::addString(const TextChar* string) {
			SendMessage(handle(), CB_ADDSTRING, 0, (LPARAM)string);
		}
	}
}