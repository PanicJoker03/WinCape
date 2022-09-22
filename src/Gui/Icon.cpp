#include "Gui/Icon.hpp"
#include "Application.hpp"
namespace w_cape{
namespace ui{
	//-------------------------------------------------------------------------
	//Icon
	//-------------------------------------------------------------------------
	ui::Icon::Icon() {}
	void ui::Icon::load(RESRC_I idi)
	{
		ICO_HND iconHnd = (ICO_HND)LoadImage(
			application.instance(), MAKEINTRESOURCE(idi),
			IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE);
		handle(iconHnd);
	}
}}
