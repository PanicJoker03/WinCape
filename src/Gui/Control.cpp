#include "Gui/Control.hpp"
namespace cape{
namespace usr{
	//--------------------------------------------------------------------------
	//Control
	//--------------------------------------------------------------------------
	void usr::Control::createFromResource(
		WND_HND parent,
		int resource) {
		handle(GetDlgItem(parent, resource));
	}
}}
