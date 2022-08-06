#include "Gui/Button.hpp"
#include "Gui/Manager.hpp"
namespace WinCape::Gui
{
	//----------------------------------------------------------------------
	//Button
	//----------------------------------------------------------------------
	void Gui::Button::onClick(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Gui::Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
	}
}
