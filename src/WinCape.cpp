#include <WinCape.hpp>
#include <Helper.hpp>
using namespace std;
//Manage procedure messages here
namespace
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
		return 0;
	}
}
//-------------------------------------------------------------------------
//Entry point
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
	struct CommonData
	{
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
	//TODO: Check if I can prevent handle variable duplication through interfaces
	class Window::WindowImpl : Base::BaseImpl
	{
	public:
		static Window Create(const char* windowName, Rect rect, WindowStyle style)
		{
			Window window;
			Handle windowHandle;
			if (!RegisterClassEx(&WindowClass()))
			{
				int i = 0;
			}
			windowHandle = CreateWindow(
				Utility::toWchar_t(Defaults::WindowName),
				Utility::toWchar_t(Defaults::WindowName),
				Defaults::DefWindowStyle,
				rect.position.x, rect.position.y,
				rect.size.x, rect.size.y,
				NULL,
				NULL,
				Application::Instance(),
				NULL
			);
			auto var = GetLastError();
			window.setHandle(windowHandle);
			return window;
		}
		void show()
		{
			ShowWindow(BaseImpl::getHandle(), Defaults::DefShowCommand);
		}
	private:
		static WNDCLASSEX WindowClass()
		{
			//TODO wrap IDI macros in default header...
			WNDCLASSEX windowClass = {};
			windowClass.cbSize = sizeof(WNDCLASSEX);
			windowClass.style = Defaults::DefClassStyle;
			windowClass.lpfnWndProc = WndProc;
			windowClass.hInstance = Application::Instance();
			windowClass.hIcon = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
			windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			windowClass.lpszClassName = Utility::toWchar_t(Defaults::WindowName);
			windowClass.hIconSm = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
			return windowClass;
		}
	};
	Base::Base() : baseImpl{ std::make_unique<BaseImpl>() } {}
	Base::~Base() {}
	Base::Base(const Base& base) : baseImpl{ make_unique<BaseImpl>() }
	{
		setHandle(base.getHandle());
	}
	Window::Window() : windowImpl{ make_unique<WindowImpl>() } {}
	Window::~Window() {}
	Window::Window(const Window& window) : Base(window), windowImpl{ make_unique<WindowImpl>() } {}
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
	void Window::show()
	{
		windowImpl->show();
	}
	//-------------------------------------------------------------------------
	//Button
	//-------------------------------------------------------------------------
}