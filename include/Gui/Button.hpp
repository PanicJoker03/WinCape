#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "defines.hpp"
#include "Gui/Control.hpp"
namespace WinCape
{
	namespace Gui {
		class Button : public Control
		{
		public:
			void onClick(const EventCallback& callback);

		};
	}
}
#endif