#include <defaults.hpp>
#include <Gui/Manager.hpp>
#include <map>
#include <Application.hpp>
#include <WinCape.hpp>
#include "Gui/GuiDefines.hpp"
using namespace std;

namespace cape{
namespace usr{
	//--------------------------------------------------------------------------
	//Implementation
	//--------------------------------------------------------------------------
	class ManagerImpl
	{
		typedef pair<usr::Base::Handle, WND_MSG> EVE_KEY;
		//Wrap in a class?
		typedef map<EVE_KEY, EVE_CALL> EVE_MP;
		EVE_MP eventMap;
		//vector<void*> ptrPool;
		//Wrap in font class?
		FON_HND applicationFont;
	public:
		//using EVE_KEY = pair<usr::Base::Handle, WND_MSG>;
		//Wrap in a class?
		//using EVE_MP = map<EVE_KEY, EVE_CALL>;
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
		void listenEvent(usr::Base::Handle handle, WND_MSG message,
			const EVE_CALL& callback)
		{
			eventMap[EVE_KEY( handle, message  )] = callback;
		}
		void unlistenEvent(usr::Base::Handle handle, WND_MSG message) 
		{
			eventMap.erase(EVE_KEY(handle, message));
		}
		void doCallback(const EVE_KEY& key, WPARAM wParam, LPARAM lParam)
		{
			EVE_MP::iterator keyIterator = eventMap.find(key);
			if (keyIterator != eventMap.end())
			{
				keyIterator->second(EVENT( key.first , wParam, lParam ));
			}
		}
		static void TimerProc(HWND hWnd, UINT param1, UINT param2,
			UINT_PTR param3, DWORD param4){
			ManagerImpl::instance().doCallback(
				EVE_KEY(0, usr::WindowMessages::TIMER), 0, 0
			);
		}
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
			LPARAM lParam)
		{
			WND_HND handle = (usr::Base::Handle)hWnd;
			switch (message)
			{
			case usr::WindowMessages::DESTROY:
				ManagerImpl::instance().doCallback(
					EVE_KEY( handle, message ), wParam, lParam
				);
				PostQuitMessage(0);
				break;
			case usr::WindowMessages::COMMAND:
			{
				usr::Base::Handle commandHandle = (usr::Base::Handle)lParam;
				WND_MSG controlMessage = HIWORD(wParam);
				ManagerImpl::instance().doCallback(
					EVE_KEY( commandHandle, controlMessage ), wParam, lParam
				);
			}
			break;
			case usr::WindowMessages::MENU_COMMAND:
			{
				usr::Base::Handle commandHandle = (usr::Base::Handle)lParam;
				ManagerImpl::instance().doCallback(
					EVE_KEY( commandHandle, message ), wParam, lParam
				);
			}
			break;
			default:
				ManagerImpl::instance().doCallback(
					EVE_KEY( handle, message ), wParam, lParam
				);
				return DefWindowProcW(hWnd, message, wParam, lParam);
			break;
			}
			return 0;
		}
		void registerClass(CON_WSTR name = cape::Defaults::WINDOW_NAME)
		{
			//TODO wrap IDI macros in default header...
			//auto wWindowName = poolPtr(Utility::toWchar_t(name));
			WNDCLASSEXW windowClass = {};
			windowClass.cbSize = sizeof(WNDCLASSEXW);
			windowClass.style = usr::Defaults::DEFCLASS_STYLE;
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
		usr::Base::Handle createHandle(CON_WSTR name,
			CON_WSTR text, WND_STY style, const CAPE_RECT& rect,
			usr::Base::Handle parent, WNDX_STY exStyle)
		{
			WNDCLASSW windowClass = {};
			//Because each window must register it's class
			if(!GetClassInfoW(Application::instance(), name, &windowClass))
				registerClass(name);
				//MessageBoxW(0, name, L"NO manches", MB_OK);
			WND_HND handle = CreateWindowExW(
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
		void defaultFont(CON_WSTR fontName)
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
		FON_HND defaultFont()
		{
			return applicationFont;
		}
	};
	//--------------------------------------------------------------------------
	//Forwarding
	//--------------------------------------------------------------------------
	usr::Manager::Manager() {}
	usr::Manager& Manager::instance()
	{
		static Manager instance_;
		return instance_;
	}
	int usr::Manager::startListening()
	{
		return ManagerImpl::instance().startListening();
	}
	void usr::Manager::listenEvent(
		usr::Base::Handle handle, 
		WND_MSG message, const EVE_CALL& callback)
	{
		ManagerImpl::instance().listenEvent(handle, message, callback);
	}
	void usr::Manager::unlistenEvent(
		usr::Base::Handle handle, WND_MSG message)
	{
		ManagerImpl::instance().unlistenEvent(handle, message);
	}
	void usr::Manager::registerClass(CON_WSTR name)
	{
		ManagerImpl::instance().registerClass(name);
	}
	usr::Base::Handle usr::Manager::createHandle(CON_WSTR className,
		CON_WSTR text, WND_STY style, const CAPE_RECT& rect,
		usr::Base::Handle parent, WNDX_STY exStyle)
	{
		return ManagerImpl::instance().createHandle(className, text, style,
			rect, parent, exStyle);
	}
	void usr::Manager::defaultFont(CON_WSTR fontName)
	{
		ManagerImpl::instance().defaultFont(fontName);
	}
	FON_HND usr::Manager::defaultFont()
	{
		return ManagerImpl::instance().defaultFont();
	}
}}
