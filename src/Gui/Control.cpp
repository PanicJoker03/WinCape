#include "Gui/Control.hpp"
namespace wcape{
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
