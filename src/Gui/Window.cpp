#include "defines.hpp"
#include "Manager.hpp"
#include "Gui.hpp"
using namespace std;
namespace WinCape::Gui
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
		ShowWindow(handle(), ShowCommands::Show);
	}
	void Window::hide()
	{
		ShowWindow(handle(), ShowCommands::Hide);
	}
	void Window::minimize()
	{
		ShowWindow(handle(), ShowCommands::Minimize);
	}
	void Window::addButton(Button& button, const TextChar* text,
		const Vector2I& position, const Vector2I& size)
	{
		Handle buttonHandle;
		buttonHandle = Manager::instance().createHandle(
			Defaults::ButtonClassName, text, Defaults::DefButtonStyle,
			Rect{
				position,
				size
			},
			handle()
		);
		button.handle(buttonHandle);
	}
	void
	Window::addRadioButton(initializer_list<pair<Reference<RadioButton>,
		const TextChar*>> radioButtonList, const Vector2I& position,
		const Vector2I& padding)
	{
		const auto listSize = radioButtonList.size();
		for (auto i = 0; i < listSize; i++)
		{
			Handle radioButtonHandle;
			RadioButton& radioButton = radioButtonList.begin()[i].first;
			const TextChar* caption = radioButtonList.begin()[i].second;
			Vector2I position_ = position;
			position_.x += padding.x * i;
			position_.y += padding.y * i;
			const bool isLast = (i == (listSize - 1));
			const ButtonStyle style =
				isLast ?
					Defaults::RadioButtonStyle | WindowStyles::Group
					:
					Defaults::RadioButtonStyle;
			radioButtonHandle = Manager::instance().createHandle(
				Defaults::ButtonClassName, caption, style,
				Rect{
					position_,
					Defaults::ButtonSize
				},
				handle()
			);
			radioButton.handle(radioButtonHandle);
		}
	}
	void Window::attachMenu(Menu& menu)
	{
		SetMenu(handle(), menu.handle());
		DrawMenuBar(handle());
	}
	void Window::onPaint(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Manager::instance().listenEvent(
			handle(), WindowMessages::Paint, callback
		);
	}
	void Window::onDestroy(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Manager::instance().listenEvent(
			handle(), WindowMessages::Destroy, callback
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
		SendMessage(handle(), WindowMessages::Close, 0, 0);
	}
	void Window::setIcon(const Icon& icon)
	{
		SendMessage(
			handle(), WindowMessages::SetIcon, ICON_BIG, (LPARAM)icon.handle()
		);
	}
	void Window::timer(const EventCallback& callback, unsigned int time){
		WindowMessage timerMsg = WindowMessages::Timer;
		Manager::instance().listenEvent(handle(), timerMsg, callback);
		SetTimer(
			handle(), reinterpret_cast<UINT_PTR>(
				handle()
			),
			time, AsNull<TIMERPROC>::value
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
			handle(), 0, value, LayeredWindowAttributes::Alpha);
	}
	Window::~Window()
	{
		//if(handle() != NullPointer)
		//	DestroyWindow(handle());
	}
}
