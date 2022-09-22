#include "defines.hpp"
#include "Ui/Manager.hpp"
#include "Gui.hpp"
#include "Event.hpp"
using namespace std;
namespace w_cape{
namespace ui
{
	//--------------------------------------------------------------------------
	//Window
	//--------------------------------------------------------------------------
	Window::Window() {}
	Window::Window(WND_HND value)
	{
		handle(value);
	}
	void Window::show()
	{
		ShowWindow(handle(), ShowCommands::SHOW);
	}
	void Window::hide()
	{
		ShowWindow(handle(), ShowCommands::HIDE);
	}
	void Window::minimize()
	{
		ShowWindow(handle(), ShowCommands::MINI);
	}
	void Window::addButton(Button& button, WSTR_CON text,
		const VEC_2I& position, const VEC_2I& size)
	{
		Handle buttonHandle;
		buttonHandle = ui::Manager::instance().createHandle(
			Defaults::BUTTON_CLASS_NAME, text, Defaults::DEFBUTTON_STYLE,
			CAPE_RECT(
				position,
				size
			),
			handle()
		);
		button.handle(buttonHandle);
	}
	//Omited at the moment
	//void Window::addRadioButton(initializer_list<pair<Reference<RadioButton>,
	//	WSTR_CON>> radioButtonList, const VEC_2I& position,
	//	const VEC_2I& padding)
	//{
	//	const auto listSize = radioButtonList.size();
	//	for (auto i = 0; i < listSize; i++)
	//	{
	//		Handle radioButtonHandle;
	//		RadioButton& radioButton = radioButtonList.begin()[i].first;
	//		WSTR_CON caption = radioButtonList.begin()[i].second;
	//		VEC_2I position_ = position;
	//		position_.x += padding.x * i;
	//		position_.y += padding.y * i;
	//		const bool isLast = (i == (listSize - 1));
	//		const BTN_STY style =
	//			isLast ?
	//				Defaults::RadioButtonStyle | WindowStyles::Group
	//				:
	//				Defaults::RadioButtonStyle;
	//		radioButtonHandle = Manager::instance().createHandle(
	//			Defaults::ButtonClassName, caption, style,
	//			CAPE_RECT{
	//				position_,
	//				Defaults::ButtonSize
	//			},
	//			handle()
	//		);
	//		radioButton.handle(radioButtonHandle);
	//	}
	//}

	void Window::addListView(
		ListView & listView, const CAPE_RECT & dimensions, const VEC_2I& padding)
	{
	    Handle listViewHandle;
	    const LVW_STY style =
			WindowStyles::CHILD |
			WindowStyles::VISIBLE |
			ListViewStyles::REPORT;
	    CAPE_RECT dimensions_ = dimensions;
	    dimensions_.position.x += padding.x;
	    dimensions_.position.y += padding.y;
	    listViewHandle = ui::Manager::instance().createHandle(ClassNames::LST_VIW, L"", style, dimensions_, handle());
	    listView.handle(listViewHandle);
	}

	void Window::attachMenu(Menu& menu)
	{
		SetMenu(handle(), menu.handle());
		DrawMenuBar(handle());
	}
	void Window::onPaint(const EVE_CALL& callback)
	{
		//TODO: declare button notifications in defines
		ui::Manager::instance().listenEvent(
			handle(), WindowMessages::PINT, callback
		);
	}
	void Window::onDestroy(const EVE_CALL& callback)
	{
		//TODO: declare button notifications in defines
		ui::Manager::instance().listenEvent(
			handle(), WindowMessages::D_TROY, callback
		);
	}
	void Window::redraw()
	{
		RedrawWindow(handle(), 0, 0, RDW_INVALIDATE | RDW_UPDATENOW);
	}
	ui::DeviceContext ui::Window::deviceContext()
	{
		ui::DeviceContext deviceContext;
		deviceContext.handle(GetDC(handle()));
		return deviceContext;
	}
	void Window::close()
	{
		SendMessage(handle(), WindowMessages::CLOS, 0, 0);
	}
	void Window::setIcon(const Icon& icon)
	{
		SendMessage(
			handle(), WindowMessages::SET_ICO, ICON_BIG, (LPARAM)icon.handle()
		);
	}
	void Window::timer(const EVE_CALL& callback, unsigned int time){
		WND_MSG timerMsg = WindowMessages::TIME;
		ui::Manager::instance().listenEvent(handle(), timerMsg, callback);
		SetTimer(
			handle(), reinterpret_cast<UINT_PTR>(
				handle()
			),
			time, NULL
		);
	}
	void Window::alpha(const BYTE value){
		/*
		bool ok = SetLayeredWindowAttributes(
			handle(), 0, value, LayeredWindowAttributes::Alpha
		);
		if(!ok)
			throw GetLastError();
			*/
		SetLayeredWindowAttributes(
			handle(), 0, value, LayeredWindowAttributes::ALPH);
	}
	void Window::parent(Window window){
		SetParent(handle(), window.handle());
	}
	Window Window::parent(){
		return Window(GetParent(handle()));
	}
	Window::~Window()
	{
		//if(handle() != NullPointer)
		//	DestroyWindow(handle());
	}
}}
