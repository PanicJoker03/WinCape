#include "Gui/Combobox.hpp"
namespace cape{
namespace usr{
	//----------------------------------------------------------------------
	//ComboBox
	//----------------------------------------------------------------------
	void usr::ComboBox::addString(CON_WSTR string) {
		SendMessage(handle(), CB_ADDSTRING, 0, (LPARAM)string);
	}
}}
