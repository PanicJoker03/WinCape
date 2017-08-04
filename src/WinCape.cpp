#include <WinCape.hpp>
#include <Manager.hpp>
#include <Helper.hpp>
#include <vector>
#include <map>
using namespace std;
//-------------------------------------------------------------------------
//Application
//-------------------------------------------------------------------------
int Application::run()
{
	return WinCape::Manager::instance().startListening();
}
int Application::run(WinCape::WindowFrame& window)
{
	WinCape::Window::create(window, window.windowName, window.rect, window.style);
	window.onCreate();
	return WinCape::Manager::instance().startListening();
}
InstanceHandle Application::instance()
{
	return GetModuleHandle(NULL);
}
void Application::defaultFont(const wchar_t* fontName)
{
	WinCape::Manager::instance().defaultFont(fontName);
}
namespace WinCape
{
	//-------------------------------------------------------------------------
	//HasHandle
	//-------------------------------------------------------------------------
	template<typename T> HasHandle<T>::HasHandle() {}
	template<typename T> void HasHandle<T>::handle(const T& handle)
	{
		this->_handle = handle;
	}
	template<typename T> T HasHandle<T>::handle() const
	{
		return _handle;
	}
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(const wchar_t* text)
	{
		SetWindowText(handle(), text);
	}
	//-------------------------------------------------------------------------
	//Window
	//-------------------------------------------------------------------------
	Window& Window::create(Window& window, const wchar_t* windowName, Rect rect, WindowStyle style)
	{
		Handle windowHandle;
		//RegisterClassEx(&WindowClass());
		Manager::instance().registerClass();
		windowHandle = Manager::instance().createHandle(Defaults::WindowName, windowName, style, rect);
		window.handle(windowHandle);
		return window;
	}
	void Window::show()
	{
		ShowWindow(handle(), ShowCommands::Show);
	}
	void Window::minimize()
	{
		ShowWindow(handle(), ShowCommands::Minimize);
	}
	void Window::addButton(Button& button, const wchar_t* text, const Int2& position, const Int2& size)
	{
		Handle buttonHandle;
		buttonHandle = Manager::instance().createHandle(Defaults::ButtonClassName, text, Defaults::DefButtonStyle, Rect{ position, size }, handle());
		button.handle(buttonHandle);
		//could be wrapped in setFont function(menctioned in header file)...
		//auto a = Manager::Instance().defaultFont();
		SendMessage(button.handle(), WM_SETFONT, (WPARAM)Manager::instance().defaultFont(), (LPARAM)MAKELONG(TRUE, 0));
	}
	void Window::addRadioButton(initializer_list<pair<Reference<RadioButton>, const wchar_t*>> radioButtonList, const Int2& position, const Int2& padding)
	{
		const auto listSize = radioButtonList.size();
		for (auto i = 0; i < listSize; i++)
		{
			Handle radioButtonHandle;
			RadioButton& radioButton = radioButtonList.begin()[i].first;
			const wchar_t* caption = radioButtonList.begin()[i].second;
			Int2 position_ = position;
			position_.x += padding.x * i;
			position_.y += padding.y * i;
			const bool isLast = (i == (listSize - 1));
			const ButtonStyle style = isLast ? Defaults::RadioButtonStyle | WindowStyles::Group : Defaults::RadioButtonStyle;
			radioButtonHandle = Manager::instance().createHandle(Defaults::ButtonClassName, caption, style, Rect{ position_, Defaults::ButtonSize }, handle());
			radioButton.handle(radioButtonHandle);
			//could be wrapped in setFont function(menctioned in header file)...
			SendMessage(radioButton.handle(), WM_SETFONT, (WPARAM)Manager::instance().defaultFont(), (LPARAM)MAKELONG(TRUE, 0));
		}
	}
	void Window::onPaint(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Manager::instance().listenEvent(handle(), WindowMessages::Paint, callback);
	}
	//-------------------------------------------------------------------------
	//Button
	//-------------------------------------------------------------------------
	void Button::onClick(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
	}
	//-------------------------------------------------------------------------
	//WindowFrame
	//-------------------------------------------------------------------------
	WindowFrame::WindowFrame(const wchar_t* windowName, Rect rect, WindowStyle style)
		:windowName(windowName), rect(rect), style(style) {}
	WindowFrame::~WindowFrame() {}
	//-------------------------------------------------------------------------
	//DeviceContext
	//-------------------------------------------------------------------------
	DeviceContext::~DeviceContext() 
	{
		if (handle())
			DeleteDC(handle());
	}
	//-------------------------------------------------------------------------
	//Avoiding template linkage errors
	//-------------------------------------------------------------------------
	template class HasHandle<BaseHandle>;
	template class HasHandle<DeviceContextHandle>;
}