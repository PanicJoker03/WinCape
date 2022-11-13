#include "Ui/Control.h"
namespace w_cape{
namespace ui{
	//--------------------------------------------------------------------------
	//Control
	//--------------------------------------------------------------------------
	void ui::Control::createFromResource(
		WND_HND parent,
		int resource) {
		handle(GetDlgItem(parent, resource));
	}
}}
