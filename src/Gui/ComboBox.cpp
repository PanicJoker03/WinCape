#include "Gui/Combobox.hpp"
namespace wcape{
namespace usr{
	//----------------------------------------------------------------------
	//ComboBox
	//----------------------------------------------------------------------
	void usr::ComboBox::addString(WSTR_CON string) {
		SendMessage(handle(), CB_ADDSTRING, 0, (LPARAM)string);
	}
}}
