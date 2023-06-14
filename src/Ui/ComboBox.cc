#include "Ui/Combobox.h"
namespace w_cape{
namespace ui{
	//----------------------------------------------------------------------
	//ComboBox
	//----------------------------------------------------------------------
	void ui::ComboBox::addString(WCH_STR_CONST string) {
		SendMessage(handle(), CB_ADDSTRING, 0, (LPARAM)string);
	}
}}
