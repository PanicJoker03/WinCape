#include "Gui/Button.hpp"
#include "Gui/Manager.hpp"
namespace wcape{
namespace usr{
	//----------------------------------------------------------------------
	//Button
	//----------------------------------------------------------------------
	void usr::Button::onClick(const EVE_CALL& callback)
	{
		//TODO: declare button notifications in defines
		usr::Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
	}
}}
