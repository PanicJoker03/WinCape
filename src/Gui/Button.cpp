#include "Gui/Button.hpp"
#include "Manager.hpp"
namespace WinCape
{
	namespace Gui {
		//-------------------------------------------------------------------------
		//Button
		//-------------------------------------------------------------------------
		void Gui::Button::onClick(const EventCallback& callback)
		{
			//TODO: declare button notifications in defines
			Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
		}
	}
}