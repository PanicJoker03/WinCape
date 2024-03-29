#include "Ui/Button.h"
#include "Ui/Manager.h"
namespace w_cape{
namespace ui{
	//----------------------------------------------------------------------
	//Button
	//----------------------------------------------------------------------
	void ui::Button::onClick(const EVE_CALL& callback)
	{
		//TODO: declare button notifications in defines
		ui::Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
	}
}}
