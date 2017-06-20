#include <WinCape.hpp>
#include <Helper.hpp>
#include <vector>
using namespace std;
//Manage procedure messages here
namespace
{
	using namespace WinCape;
	vector<void*> ptrPool;
	//Forward declarations
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void* poolPtr(void* ptr);
	void freeMemory();
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		//TODO: abstract message processing
		switch (message)
		{
		case WindowMessages::General::Destroy:
			PostQuitMessage(0);
			freeMemory();
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
		return 0;
	}
	void* poolPtr(void* ptr)
	{
		ptrPool.push_back(ptr);
		return ptr;
	}
	void freeMemory()
	{
		for (auto& ptr : ptrPool)
		{
			delete ptr;
		}
	}
}
//-------------------------------------------------------------------------
//Application
//-------------------------------------------------------------------------
int Application::Run()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}
InstanceHandle Application::Instance()
{
	return GetModuleHandle(0);
}
namespace WinCape
{
	//-------------------------------------------------------------------------
	//Impl classes definitions
	//-------------------------------------------------------------------------
	class Base::BaseImpl
	{
	public:
		void setHandle(const Handle& handle)
		{
			this->handle = handle;
		}
		Handle getHandle() const
		{
			return handle;
		}
		Handle handle = 0;
	};
	class Window::WindowImpl
	{
	public:
		static Window Create(const char* windowName, Rect rect, WindowStyle style)
		{
			Window window;
			Handle windowHandle;
			RegisterClassEx(&WindowClass());
			auto wideWindowName = poolPtr(Utility::toWchar_t(windowName));
			windowHandle = CreateWindow(
				static_cast<LPWSTR>(wideWindowName),
				static_cast<LPWSTR>(wideWindowName),
				style,
				rect.position.x, rect.position.y,
				rect.size.x, rect.size.y,
				NULL,
				NULL,
				Application::Instance(),
				NULL
			);
			window.setHandle(windowHandle);
			return window;
		}
		void addButton(Button& button, const char* text, const Rect& rect, const Handle& parent)
		{
			Handle buttonHandle;
			auto buttonText = static_cast<LPWSTR>(poolPtr(Utility::toWchar_t(text)));
			buttonHandle = CreateWindow(
				Defaults::ButtonClassName,
				buttonText,
				//TODO: Add button style missing here...
				WindowStyles::TabStop | WindowStyles::Visible | WindowStyles::Child,
				rect.position.x,
				rect.position.y,
				rect.size.x,
				rect.size.y,
				parent,
				NULL,
				Application::Instance(),
				NULL);
			button.setHandle(buttonHandle);
		}
		void show(const Handle& handle)
		{
			ShowWindow(handle, Defaults::DefShowCommand);
		}
	private:
		static WNDCLASSEX WindowClass()
		{
			auto wideWindowName = poolPtr(Utility::toWchar_t(Defaults::WindowName));
			//TODO wrap IDI macros in default header...
			WNDCLASSEX windowClass = {};
			windowClass.cbSize = sizeof(WNDCLASSEX);
			windowClass.style = Defaults::DefClassStyle;
			windowClass.lpfnWndProc = WndProc;
			windowClass.hInstance = Application::Instance();
			windowClass.hIcon = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
			windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			windowClass.lpszClassName = (LPWSTR)wideWindowName;
			windowClass.hIconSm = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
			return windowClass;
		}
	};
	class Control::ControlImpl
	{
	public:
	};
	class Button::ButtonImpl
	{
	public:
	};
	//-------------------------------------------------------------------------
	//Making classes copyable
	//-------------------------------------------------------------------------
	Base::Base() : baseImpl{ std::make_unique<BaseImpl>() } {}
	Base::~Base() {}
	Base::Base(const Base& base) : baseImpl{ make_unique<BaseImpl>() }
	{
		setHandle(base.getHandle());
	}
	Window::Window() : windowImpl{ make_unique<WindowImpl>() } {}
	Window::~Window() {}
	Window::Window(const Window& window) : Base(window), windowImpl{ make_unique<WindowImpl>() } {}
	Control::Control() : controlImpl{ make_unique<ControlImpl>() } {}
	Control::~Control() {}
	Control::Control(const Control& control) : Base(control), controlImpl{ make_unique<ControlImpl>() } {}
	Button::Button() : buttonImpl{ make_unique<ButtonImpl>() } {}
	Button::~Button() {}
	Button::Button(const Button& button) : Control(button), buttonImpl{ make_unique<ButtonImpl>() } {}
	//forwarding functions
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	void Base::setHandle(const Handle& handle)
	{
		baseImpl->setHandle(handle);
	}
	Handle Base::getHandle() const
	{
		return baseImpl->getHandle();
	}
	//-------------------------------------------------------------------------
	//Window
	//-------------------------------------------------------------------------
	Window Window::Create(const char* windowName, Rect rect, WindowStyle style)
	{
		return WindowImpl::Create(windowName, rect, style);
	}
	Window& Window::show()
	{
		windowImpl->show(getHandle());
		return *this;
	}
	Window& Window::addButton(Button& button, const char* text, const Int2& position, const Int2& size)
	{
		windowImpl->addButton(button, text, Rect{position, size}, getHandle());
		return *this;
	}
	//-------------------------------------------------------------------------
	//Button
	//-------------------------------------------------------------------------
}