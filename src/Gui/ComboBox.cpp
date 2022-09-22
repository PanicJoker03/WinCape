#include "Gui/Combobox.hpp"
namespace w_cape{
namespace ui{
	//----------------------------------------------------------------------
	//ComboBox
	//----------------------------------------------------------------------
	void ui::ComboBox::addString(WSTR_CON string) {
		SendMessage(handle(), CB_ADDSTRING, 0, (LPARAM)string);
	}
}}
