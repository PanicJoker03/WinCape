#include "Gui/Icon.hpp"
#include "Application.hpp"
namespace WinCape::Gui
{
	//-------------------------------------------------------------------------
	//Icon
	//-------------------------------------------------------------------------
	Gui::Icon::Icon() {}
	void Gui::Icon::load(ResourceInt idi)
	{
		IconHandle iconHandle = (IconHandle)LoadImage(
			Application::instance(), MAKEINTRESOURCE(idi),
			IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE);
		handle(iconHandle);
	}
}
