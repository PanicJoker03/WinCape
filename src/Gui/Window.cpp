#include "defines.hpp"
#include "Gui/Manager.hpp"
#include "Gui.hpp"
#include "Event.hpp"
using namespace std;
namespace WinCape{
namespace Gui
{
	//--------------------------------------------------------------------------
	//Window
	//--------------------------------------------------------------------------
	Window::Window() {}
	Window::Window(WindowHandle value)
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
		ShowWindow(handle(), ShowCommands::MINIMIZE);
	}
	void Window::addButton(Button& button, const wchar_t* text,
		const Vector2I& position, const Vector2I& size)
	{
		Handle buttonHandle;
		buttonHandle = Gui::Manager::instance().createHandle(
			Defaults::BUTTON_CLASS_NAME, text, Defaults::DEFBUTTON_STYLE,
			Rect(
				position,
				size
			),
			handle()
		);
		button.handle(buttonHandle);
	}
	//Omited at the moment
	//void Window::addRadioButton(initializer_list<pair<Reference<RadioButton>,
	//	const wchar_t*>> radioButtonList, const Vector2I& position,
	//	const Vector2I& padding)
	//{
	//	const auto listSize = radioButtonList.size();
	//	for (auto i = 0; i < listSize; i++)
	//	{
	//		Handle radioButtonHandle;
	//		RadioButton& radioButton = radioButtonList.begin()[i].first;
	//		const wchar_t* caption = radioButtonList.begin()[i].second;
	//		Vector2I position_ = position;
	//		position_.x += padding.x * i;
	//		position_.y += padding.y * i;
	//		const bool isLast = (i == (listSize - 1));
	//		const ButtonStyle style =
	//			isLast ?
	//				Defaults::RadioButtonStyle | WindowStyles::Group
	//				:
	//				Defaults::RadioButtonStyle;
	//		radioButtonHandle = Manager::instance().createHandle(
	//			Defaults::ButtonClassName, caption, style,
	//			Rect{
	//				position_,
	//				Defaults::ButtonSize
	//			},
	//			handle()
	//		);
	//		radioButton.handle(radioButtonHandle);
	//	}
	//}

	void Window::addListView(
		ListView & listView, const Rect & dimensions, const Vector2I& padding)
	{
	    Handle listViewHandle;
	    const ListViewStyle style =
			WindowStyles::CHILD |
			WindowStyles::VISIBLE |
			ListViewStyles::REPORT;
	    Rect dimensions_ = dimensions;
	    dimensions_.position.x += padding.x;
	    dimensions_.position.y += padding.y;
	    listViewHandle = Gui::Manager::instance().createHandle(ClassNames::LISTVIEW, L"", style, dimensions_, handle());
	    listView.handle(listViewHandle);
	}

	void Window::attachMenu(Menu& menu)
	{
		SetMenu(handle(), menu.handle());
		DrawMenuBar(handle());
	}
	void Window::onPaint(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Gui::Manager::instance().listenEvent(
			handle(), WindowMessages::PAINT, callback
		);
	}
	void Window::onDestroy(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Gui::Manager::instance().listenEvent(
			handle(), WindowMessages::DESTROY, callback
		);
	}
	void Window::redraw()
	{
		RedrawWindow(handle(), 0, 0, RDW_INVALIDATE | RDW_UPDATENOW);
	}
	Gui::DeviceContext Gui::Window::deviceContext()
	{
		Gui::DeviceContext deviceContext;
		deviceContext.handle(GetDC(handle()));
		return deviceContext;
	}
	void Window::close()
	{
		SendMessage(handle(), WindowMessages::CLOSE, 0, 0);
	}
	void Window::setIcon(const Icon& icon)
	{
		SendMessage(
			handle(), WindowMessages::SET_ICON, ICON_BIG, (LPARAM)icon.handle()
		);
	}
	void Window::timer(const EventCallback& callback, unsigned int time){
		WindowMessage timerMsg = WindowMessages::TIMER;
		Gui::Manager::instance().listenEvent(handle(), timerMsg, callback);
		SetTimer(
			handle(), reinterpret_cast<UINT_PTR>(
				handle()
			),
			time, NULL
		);
	}
	void Window::alpha(const Byte value){
		/*
		bool ok = SetLayeredWindowAttributes(
			handle(), 0, value, LayeredWindowAttributes::Alpha
		);
		if(!ok)
			throw GetLastError();
			*/
		SetLayeredWindowAttributes(
			handle(), 0, value, LayeredWindowAttributes::ALPHA);
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
