#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "defines.hpp"
#include "GuiDefaults.hpp"
#include "Ui/Base.hpp"
#include "Ui/DeviceContext.hpp"
#include "Ui/Icon.hpp"
#include "Ui/Button.hpp"
#include "Ui/ListView.hpp"
#include "Ui/RadioButton.hpp"
#include "Ui/Menu.hpp"
namespace w_cape{
namespace ui{
	class Window : public Base
	{
	public:
		Window();
		Window(WND_HND value);
		void show();
		void hide();
		void minimize();

		void addButton(Button& button, WSTR_CON text,
			const VEC_2I& position,
			const VEC_2I& size = Defaults::BUTTON_SIZE);

		//Omited at the moment
        //void addRadioButton(
		//		std::initializer_list<std::pair<Reference<RadioButton>,
		//		WSTR_CON>> radioButtonList, const VEC_2I& position,
		//		const VEC_2I& padding = Defaults::RadioButtonPadding);

        void addListView(ListView & listView, const CAPE_RECT & dimensions, const VEC_2I & padding = VEC_2I());
		void attachMenu(Menu& menu);
		void onDestroy(const EVE_CALL& callback);
		void onPaint(const EVE_CALL& callback);
		void redraw();
		void close();
		void setIcon(const Icon& icon);
		void timer(const EVE_CALL& callback, unsigned int time);
		void alpha(const BYTE value);
		DeviceContext deviceContext();
		void parent(Window window);
		Window parent();
		~Window();
	};
}}
#endif
