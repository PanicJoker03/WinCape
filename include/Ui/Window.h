#ifndef WINDOW_H
#define WINDOW_H
#include "defines.h"
#include "UiDefaults.h"
#include "Ui/Base.h"
#include "Ui/DeviceContext.h"
#include "Ui/Icon.h"
#include "Ui/Button.h"
#include "Ui/ListView.h"
#include "Ui/RadioButton.h"
#include "Ui/Menu.h"
namespace w_cape{
namespace ui{
	class Window : public Base
	{
	public:
		Window();
		Window(WND_HND value);
		void show() const;
		void hide() const;
		void minimize() const;
		void maximize() const;
		void restore() const;

		void addButton(Button& button, WCH_STR_CONST text,
			const I_VEC_2& position,
			const I_VEC_2& size = Defaults::BUTTON_SIZE);

		//Omited at the moment
        //void addRadioButton(
		//		std::initializer_list<std::pair<Reference<RadioButton>,
		//		WCH_STR_CONST>> radioButtonList, const I_VEC_2& position,
		//		const I_VEC_2& padding = Defaults::RadioButtonPadding);

        void addListView(ListView & listView, const CAPE_RECT & dimensions, const I_VEC_2 & padding = I_VEC_2());
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
