#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Gui/Base.hpp"
#include "Gui/DeviceContext.hpp"
#include "Gui/Icon.hpp"
#include "Gui/Button.hpp"
#include "Gui/RadioButton.hpp"
#include "Gui/Menu.hpp"
namespace WinCape
{
	namespace Gui{
		class Window : public Base
		{
		public:
			Window();
			Window(WindowHandle value);
			void show();
			void hide();
			void minimize();
			void addButton(Button& button, const TextChar* text, const Vector2I& position, const Vector2I& size = Defaults::ButtonSize);
			void addRadioButton(std::initializer_list<std::pair<Reference<RadioButton>, const TextChar*>> radioButtonList, const Vector2I& position, const Vector2I& padding = Defaults::RadioButtonPadding);
			void attachMenu(Menu& menu);
			void onDestroy(const EventCallback& callback);
			void onPaint(const EventCallback& callback);
			void redraw();
			void close();
			void setIcon(const Icon& icon);
			void timer(const EventCallback& callback, unsigned int time);
			DeviceContext deviceContext();
			~Window();
		};
	}
}
#endif
