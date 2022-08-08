#include <defaults.hpp>
#include <Gui/Manager.hpp>
#include <map>
#include <Application.hpp>
#include <WinCape.hpp>
#include "Gui/GuiDefines.hpp"
using namespace std;

namespace WinCape{
namespace Gui{
	//--------------------------------------------------------------------------
	//Implementation
	//--------------------------------------------------------------------------
	class ManagerImpl
	{
		typedef pair<Gui::Base::Handle, WindowMessage> EventKey;
		//Wrap in a class?
		typedef map<EventKey, EventCallback> EventMap;
		EventMap eventMap;
		//vector<void*> ptrPool;
		//Wrap in font class?
		FontHandle applicationFont;
	public:
		//using EventKey = pair<Gui::Base::Handle, WindowMessage>;
		//Wrap in a class?
		//using EventMap = map<EventKey, EventCallback>;
		static ManagerImpl& instance()
		{
			static ManagerImpl instance_;
			return instance_;
		}

		//void* poolPtr(void* ptr)
		//{
		//    ptrPool.push_back(ptr);
		//    return ptr;
		//}

		//void freeMemory()
		//{
		//    for(auto& ptr : ptrPool)
		//    {
        //        delete ptr;
		//    }
		//}

		int startListening()
		{
			MSG msg;
			while (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
			return static_cast<int>(msg.wParam);
		}
		void listenEvent(Gui::Base::Handle handle, WindowMessage message,
			const EventCallback& callback)
		{
			eventMap[EventKey( handle, message  )] = callback;
		}
		void unlistenEvent(Gui::Base::Handle handle, WindowMessage message) 
		{
			eventMap.erase(EventKey(handle, message));
		}
		void doCallback(const EventKey& key, WPARAM wParam, LPARAM lParam)
		{
			EventMap::iterator keyIterator = eventMap.find(key);
			if (keyIterator != eventMap.end())
			{
				keyIterator->second(Event( key.first , wParam, lParam ));
			}
		}
		static void TimerProc(HWND hWnd, UINT param1, UINT param2,
			UINT_PTR param3, DWORD param4){
			ManagerImpl::instance().doCallback(
				EventKey(0, Gui::WindowMessages::TIMER), 0, 0
			);
		}
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
			LPARAM lParam)
		{
			WindowHandle handle = (Gui::Base::Handle)hWnd;
			switch (message)
			{
			case Gui::WindowMessages::DESTROY:
				ManagerImpl::instance().doCallback(
					EventKey( handle, message ), wParam, lParam
				);
				PostQuitMessage(0);
				break;
			case Gui::WindowMessages::COMMAND:
			{
				Gui::Base::Handle commandHandle = (Gui::Base::Handle)lParam;
				WindowMessage controlMessage = HIWORD(wParam);
				ManagerImpl::instance().doCallback(
					EventKey( commandHandle, controlMessage ), wParam, lParam
				);
			}
			break;
			case Gui::WindowMessages::MENU_COMMAND:
			{
				Gui::Base::Handle commandHandle = (Gui::Base::Handle)lParam;
				ManagerImpl::instance().doCallback(
					EventKey( commandHandle, message ), wParam, lParam
				);
			}
			break;
			default:
				ManagerImpl::instance().doCallback(
					EventKey( handle, message ), wParam, lParam
				);
				return DefWindowProcW(hWnd, message, wParam, lParam);
			break;
			}
			return 0;
		}
		void registerClass(const wchar_t* name = WinCape::Defaults::WINDOW_NAME)
		{
			//TODO wrap IDI macros in default header...
			//auto wWindowName = poolPtr(Utility::toWchar_t(name));
			WNDCLASSEXW windowClass = {};
			windowClass.cbSize = sizeof(WNDCLASSEXW);
			windowClass.style = Gui::Defaults::DEFCLASS_STYLE;
			windowClass.lpfnWndProc = WndProc;
			windowClass.hInstance = Application::instance();
			windowClass.hIcon = LoadIconW(
				windowClass.hInstance, MAKEINTRESOURCEW(32512)//
			);
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
			windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			windowClass.lpszClassName = name;
			windowClass.hIconSm = LoadIconW(
				windowClass.hInstance, MAKEINTRESOURCEW(32512)//IDI_APPLICATION
			);
			RegisterClassExW(&windowClass);
		}
		Gui::Base::Handle createHandle(const wchar_t* name,
			const wchar_t* text, WindowStyle style, const Rect& rect,
			Gui::Base::Handle parent, WindowExtendedStyle exStyle)
		{
			WNDCLASSW windowClass = {};
			//Because each window must register it's class
			if(!GetClassInfoW(Application::instance(), name, &windowClass))
				registerClass(name);
				//MessageBoxW(0, name, L"NO manches", MB_OK);
			WindowHandle handle = CreateWindowExW(
				exStyle,
				name,
				text,
				style,
				rect.position.x, rect.position.y,
				rect.size.x, rect.size.y,
				parent,
				NULL,
				Application::instance(),
				NULL
			);
			int err = GetLastError();
			SendMessageW(
				handle, WM_SETFONT, (WPARAM)Manager::instance().defaultFont(),
				(LPARAM)MAKELONG(TRUE, 0)
			);
			return handle;
		}
		//Use font wrapper class...
		void defaultFont(const wchar_t* fontName)
		{
			//http://www.cplusplus.com/forum/windows/109795/
			DeleteObject(applicationFont);
			LOGFONTW lFont = {};
			lFont.lfHeight = 16;
			#ifdef _WIN32
			wcscpy_s(lFont.lfFaceName, wcsnlen_s(fontName + 1, 256), fontName);
			#else
			wcscpy(lFont.lfFaceName, fontName);
			#endif
			applicationFont = CreateFontIndirectW(&lFont);
		}
		FontHandle defaultFont()
		{
			return applicationFont;
		}
	};
	//--------------------------------------------------------------------------
	//Forwarding
	//--------------------------------------------------------------------------
	Gui::Manager::Manager() {}
	Gui::Manager& Manager::instance()
	{
		static Manager instance_;
		return instance_;
	}
	int Gui::Manager::startListening()
	{
		return ManagerImpl::instance().startListening();
	}
	void Gui::Manager::listenEvent(
		Gui::Base::Handle handle, 
		WindowMessage message, const EventCallback& callback)
	{
		ManagerImpl::instance().listenEvent(handle, message, callback);
	}
	void Gui::Manager::unlistenEvent(
		Gui::Base::Handle handle, WindowMessage message)
	{
		ManagerImpl::instance().unlistenEvent(handle, message);
	}
	void Gui::Manager::registerClass(const wchar_t* name)
	{
		ManagerImpl::instance().registerClass(name);
	}
	Gui::Base::Handle Gui::Manager::createHandle(const wchar_t* className,
		const wchar_t* text, WindowStyle style, const Rect& rect,
		Gui::Base::Handle parent, WindowExtendedStyle exStyle)
	{
		return ManagerImpl::instance().createHandle(className, text, style,
			rect, parent, exStyle);
	}
	void Gui::Manager::defaultFont(const wchar_t* fontName)
	{
		ManagerImpl::instance().defaultFont(fontName);
	}
	FontHandle Gui::Manager::defaultFont()
	{
		return ManagerImpl::instance().defaultFont();
	}
}}
