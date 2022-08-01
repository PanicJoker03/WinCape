#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "defines.hpp"
#include "GuiDefaults.hpp"
#include "Gui/Base.hpp"
#include "Gui/DeviceContext.hpp"
#include "Gui/Icon.hpp"
#include "Gui/Button.hpp"
#include "Gui/ListView.hpp"
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

			void addButton(Button& button, const wchar_t* text,
				const Vector2I& position,
				const Vector2I& size = Defaults::ButtonSize);

			void addRadioButton(
					std::initializer_list<std::pair<Reference<RadioButton>,
					const wchar_t*>> radioButtonList, const Vector2I& position,
					const Vector2I& padding = Defaults::RadioButtonPadding);

            void addListView(ListView & listView, const Rect & dimensions, const Vector2I & padding = {});
			void attachMenu(Menu& menu);
			void onDestroy(const EventCallback& callback);
			void onPaint(const EventCallback& callback);
			void redraw();
			void close();
			void setIcon(const Icon& icon);
			void timer(const EventCallback& callback, unsigned int time);
			void alpha(const Byte value);
			DeviceContext deviceContext();
			void parent(Window window);
			Window parent();
			~Window();
		};
	}
}
#endif
