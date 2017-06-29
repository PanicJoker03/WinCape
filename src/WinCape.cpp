#include <WinCape.hpp>
#include <Helper.hpp>
#include <vector>
#include <map>
using namespace std;
//Manage procedure messages here
namespace
{
	using namespace WinCape;
	using EventKey = pair<Handle, WindowMessage>;
	//Wrap in a class?
	using EventMap = map<EventKey, EventCallback>;
	EventMap eventMap;
	//use vector of unique_ptr?
	vector<void*> ptrPool;
	//Forward declarations
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void* poolPtr(void* ptr);
	void freeMemory();
	Handle CreateHandle(const char* className, const char* text, const WindowStyle& style, const Rect& rect, const Handle& parent = NULL);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		//TODO: abstract message processing
		switch (message)
		{
		case WindowMessages::General::Destroy:
			PostQuitMessage(0);
			freeMemory();
			break;
		case WM_COMMAND:
		{
			Handle handle = (Handle)lParam;
			WindowMessage controlMessage = HIWORD(wParam);
			auto key = eventMap.find(EventKey{ handle, controlMessage });
			if (key != eventMap.end())
			{
				key->second(Event{ handle, wParam, lParam });
			}
			break;
		}
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
	//This functions could be defined in another .hpp
	Handle CreateHandle(const char* className, const char* text, const WindowStyle& style, const Rect& rect, const Handle& parent)
	{
		auto wideClassName = static_cast<LPWSTR>(poolPtr(Utility::toWchar_t(className)));
		auto wideText = static_cast<LPWSTR>(poolPtr(Utility::toWchar_t(text)));
		return CreateWindow(
			wideClassName,
			wideText,
			style,
			rect.position.x, rect.position.y,
			rect.size.x, rect.size.y,
			parent,
			NULL,
			Application::Instance(),
			NULL
		);
	}
	WNDCLASSEX WindowClass()
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
	//Base
	//-------------------------------------------------------------------------
	template<typename Derived> TBase<Derived>::TBase() {}
	template<typename Derived> void TBase<Derived>::handle(const Handle& handle)
	{
		this->_handle = handle;
	}
	template<typename Derived> Handle TBase<Derived>::handle() const
	{
		return _handle;
	}
	template<typename Derived> Derived& TBase<Derived>::setText(const char* text) 
	{ 
		return static_cast<Derived&>(*this); 
	}
	//-------------------------------------------------------------------------
	//Window
	//-------------------------------------------------------------------------
	Window Window::Create(const char* windowName, Rect rect, WindowStyle style)
	{
		Window window;
		Handle windowHandle;
		RegisterClassEx(&WindowClass());
		windowHandle = CreateHandle(windowName, windowName, style, rect);
		window.handle(windowHandle);
		return window;
	}
	Window::Self& Window::show()
	{
		ShowWindow(handle(), ShowCommands::Show);
		return *this;
	}
	Window::Self& Window::minimize()
	{
		ShowWindow(handle(), ShowCommands::Minimize);
		return *this;
	}
	Window::Self& Window::addButton(Button& button, const char* text, const Int2& position, const Int2& size)
	{
		Handle buttonHandle;
		buttonHandle = CreateHandle(Defaults::ButtonClassName, text, Defaults::DefButtonStyle, Rect{ position, size }, handle());
		button.handle(buttonHandle);
		return *this;
	}
	//-------------------------------------------------------------------------
	//Button
	//-------------------------------------------------------------------------
	Button::Self& Button::onClick(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		eventMap[EventKey{ handle(), BN_CLICKED }] = callback;
		return *this;
	}
	//-------------------------------------------------------------------------
	//Avoiding template linkage errors (this could be in a separate cpp)
	//-------------------------------------------------------------------------
	template class TBase<Window>;
	template class TBase<TControl<Button>>;
}