#include "Gui/Control.hpp"
namespace WinCape::Gui
{
	//--------------------------------------------------------------------------
	//Control
	//--------------------------------------------------------------------------
	void Gui::Control::createFromResource(
		WindowHandle parent,
		int resource) {
		handle(GetDlgItem(parent, resource));
	}
}
