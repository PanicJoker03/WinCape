#include "Gui/Icon.hpp"
#include "Application.hpp"
namespace wcape{
namespace usr{
	//-------------------------------------------------------------------------
	//Icon
	//-------------------------------------------------------------------------
	usr::Icon::Icon() {}
	void usr::Icon::load(RESRC_I idi)
	{
		ICO_HND iconHnd = (ICO_HND)LoadImage(
			application.instance(), MAKEINTRESOURCE(idi),
			IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE);
		handle(iconHnd);
	}
}}
