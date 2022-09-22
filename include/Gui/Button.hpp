#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Event.hpp"
#include "Gui/Control.hpp"
namespace w_cape{
namespace ui {
	class Button : public Control
	{
	public:
		void onClick(const EVE_CALL& callback);

	};
}}
#endif
