#include <defaults.hpp>
#include <Manager.hpp>
#include <map>
#include <Application.hpp>
#include <WinCape.hpp>
using namespace std;



namespace WinCape
{
	//--------------------------------------------------------------------------
	//Implementation
	//--------------------------------------------------------------------------
	class ManagerImpl
	{
		using EventKey = pair<Gui::Base::Handle, WindowMessage>;
		//Wrap in a class?
		using EventMap = map<EventKey, EventCallback>;
		EventMap eventMap;
		//vector<void*> ptrPool;
		//Wrap in font class?
		FontHandle applicationFont = 0;
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
				DispatchMessage(&msg);
			}
			return static_cast<int>(msg.wParam);
		}
		void listenEvent(Gui::Base::Handle handle, WindowMessage message,
			const EventCallback& callback)
		{
			eventMap[EventKey{ handle, message }] = callback;
		}
		void unlistenEvent(Gui::Base::Handle handle, WindowMessage message) {
			eventMap.erase(EventKey(handle, message));
		}
		void doCallback(const EventKey& key, WPARAM wParam, LPARAM lParam)
		{
			auto keyIterator = eventMap.find(key);
			if (keyIterator != eventMap.end())
			{
				keyIterator->second(Event{ key.first , wParam, lParam });
			}
		}
		static void TimerProc(HWND hWnd, UINT param1, UINT param2,
			UINT_PTR param3, DWORD param4){
			ManagerImpl::instance().doCallback(
				EventKey{0, WindowMessages::Timer}, 0, 0
			);
		}
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
			LPARAM lParam)
		{
			auto handle = (Gui::Base::Handle)hWnd;
			switch (message)
			{
			case WindowMessages::Destroy:
				ManagerImpl::instance().doCallback(
					EventKey{ handle, message }, wParam, lParam
				);
				PostQuitMessage(0);
				break;
			case WindowMessages::Command:
			{
				Gui::Base::Handle commandHandle = (Gui::Base::Handle)lParam;
				WindowMessage controlMessage = HIWORD(wParam);
				ManagerImpl::instance().doCallback(
					EventKey{ commandHandle, controlMessage }, wParam, lParam
				);
			}
			break;
			case WindowMessages::MenuCommand:
			{
				Gui::Base::Handle commandHandle = (Gui::Base::Handle)lParam;
				ManagerImpl::instance().doCallback(
					EventKey{ commandHandle, message }, wParam, lParam
				);
			}
			break;
			default:
				ManagerImpl::instance().doCallback(
					EventKey{ handle, message }, wParam, lParam
				);
				return DefWindowProc(hWnd, message, wParam, lParam);
			break;
			}
			return 0;
		}
		void registerClass(const wchar_t* name = Defaults::WindowName)
		{
			//TODO wrap IDI macros in default header...
			//auto wWindowName = poolPtr(Utility::toWchar_t(name));
			WNDCLASSEXW windowClass = {};
			windowClass.cbSize = sizeof(WNDCLASSEX);
			windowClass.style = Defaults::DefClassStyle;
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
			auto handle = CreateWindowExW(
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
			SendMessage(
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
			LOGFONTW logFont = {};
			logFont.lfHeight = 16;
			textCopy(logFont.lfFaceName, fontName);
			applicationFont = CreateFontIndirectW(&logFont);
		}
		FontHandle defaultFont()
		{
			return applicationFont;
		}
	};
	//--------------------------------------------------------------------------
	//Forwarding
	//--------------------------------------------------------------------------
	Manager::Manager() {}
	Manager& Manager::instance()
	{
		static Manager instance_;
		return instance_;
	}
	int Manager::startListening()
	{
		return ManagerImpl::instance().startListening();
	}
	void Manager::listenEvent(Gui::Base::Handle handle, WindowMessage message,
		const EventCallback& callback)
	{
		ManagerImpl::instance().listenEvent(handle, message, callback);
	}
	void Manager::unlistenEvent(Gui::Base::Handle handle, WindowMessage message)
	{
		ManagerImpl::instance().unlistenEvent(handle, message);
	}
	void Manager::registerClass(const wchar_t* name)
	{
		ManagerImpl::instance().registerClass(name);
	}
	Gui::Base::Handle Manager::createHandle(const wchar_t* className,
		const wchar_t* text, WindowStyle style, const Rect& rect,
		Gui::Base::Handle parent, WindowExtendedStyle exStyle)
	{
		return ManagerImpl::instance().createHandle(className, text, style,
			rect, parent, exStyle);
	}
	void Manager::defaultFont(const wchar_t* fontName)
	{
		ManagerImpl::instance().defaultFont(fontName);
	}
	FontHandle Manager::defaultFont()
	{
		return ManagerImpl::instance().defaultFont();
	}
}
