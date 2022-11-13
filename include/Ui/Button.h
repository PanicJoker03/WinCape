#ifndef BUTTON_H
#define BUTTON_H
#include "Event.h"
#include "Ui/Control.h"
namespace w_cape{
namespace ui {
	class Button : public Control
	{
	public:
		void onClick(const EVE_CALL& callback);

	};
}}
#endif
