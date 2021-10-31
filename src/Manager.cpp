#include <Manager.hpp>
#include <tchar.h>
#include <map>
using namespace std;
namespace WinCape
{
	//-------------------------------------------------------------------------
	//Implementation
	//-------------------------------------------------------------------------
	class ManagerImpl
	{
		using EventKey = pair<UserGui::Base::Handle, WindowMessage>;
		//Wrap in a class?
		using EventMap = map<EventKey, EventCallback>;
		EventMap eventMap;
		//Wrap in font class?
		FontHandle applicationFont = 0;
	public:
		using EventKey = pair<UserGui::Base::Handle, WindowMessage>;
		//Wrap in a class?
		using EventMap = map<EventKey, EventCallback>;
		static ManagerImpl& instance()
		{
			static ManagerImpl instance_;
			return instance_;
		}
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
		void listenEvent(UserGui::Base::Handle handle, WindowMessage message, const EventCallback& callback)
		{
			eventMap[EventKey{ handle, message }] = callback;
		}
		void unlistenEvent(UserGui::Base::Handle handle, WindowMessage message) {
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
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			auto handle = (UserGui::Base::Handle)hWnd;
			switch (message)
			{
			case WindowMessages::Destroy:
				ManagerImpl::instance().doCallback(EventKey{ handle, message }, wParam, lParam);
				PostQuitMessage(0);
				break;
			case WindowMessages::Command:
			{
				UserGui::Base::Handle commandHandle = (UserGui::Base::Handle)lParam;
				WindowMessage controlMessage = HIWORD(wParam);
				ManagerImpl::instance().doCallback(EventKey{ commandHandle, controlMessage }, wParam, lParam);
			}
			break;
			case WindowMessages::MenuCommand:
			{
				UserGui::Base::Handle commandHandle = (UserGui::Base::Handle)lParam;
				ManagerImpl::instance().doCallback(EventKey{ commandHandle, message }, wParam, lParam);
			}
			break;
			default:
				ManagerImpl::instance().doCallback(EventKey{ handle, message }, wParam, lParam);
				return DefWindowProc(hWnd, message, wParam, lParam);
			break;
			}
			return 0;
		}
		void registerClass(const TextChar* name = Defaults::WindowName)
		{
			//TODO wrap IDI macros in default header...
			WNDCLASSEX windowClass = {};
			windowClass.cbSize = sizeof(WNDCLASSEX);
			windowClass.style = Defaults::DefClassStyle;
			windowClass.lpfnWndProc = WndProc;
			windowClass.hInstance = Application::instance();
			windowClass.hIcon = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
			windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			windowClass.lpszClassName = name;
			windowClass.hIconSm = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
			RegisterClassEx(&windowClass);
		}
		UserGui::Base::Handle createHandle(const TextChar* name, const TextChar* text, const WindowStyle& style, const Rect& rect, const UserGui::Base::Handle& parent)
		{
			WNDCLASS windowClass = {};
			//Because each window must register it's class
			if(!GetClassInfo(Application::instance(), name, &windowClass))
				registerClass(name);
			auto handle = CreateWindow(
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
			SendMessage(handle, WM_SETFONT, (WPARAM)Manager::instance().defaultFont(), (LPARAM)MAKELONG(TRUE, 0));
			return handle;
		}
		//Use font wrapper class...
		void defaultFont(const TextChar* fontName)
		{
			//http://www.cplusplus.com/forum/windows/109795/
			DeleteObject(applicationFont);
			LOGFONT logFont = {};
			logFont.lfHeight = 16;
			_tcscpy(logFont.lfFaceName, fontName);
			applicationFont = CreateFontIndirect(&logFont);
		}
		FontHandle defaultFont()
		{
			return applicationFont;
		}
	};
	//-------------------------------------------------------------------------
	//Forwarding
	//-------------------------------------------------------------------------
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
	void Manager::listenEvent(UserGui::Base::Handle handle, WindowMessage message, const EventCallback& callback)
	{
		ManagerImpl::instance().listenEvent(handle, message, callback);
	}
	void Manager::unlistenEvent(UserGui::Base::Handle handle, WindowMessage message)
	{
		ManagerImpl::instance().unlistenEvent(handle, message);
	}
	void Manager::registerClass(const TextChar* name)
	{
		ManagerImpl::instance().registerClass(name);
	}
	UserGui::Base::Handle Manager::createHandle(const TextChar* className, const TextChar* text, WindowStyle style, const Rect& rect, UserGui::Base::Handle parent)
	{
		return ManagerImpl::instance().createHandle(className, text, style, rect, parent);
	}
	void Manager::defaultFont(const TextChar* fontName)
	{
		ManagerImpl::instance().defaultFont(fontName);
	}
	FontHandle Manager::defaultFont()
	{
		return ManagerImpl::instance().defaultFont();
	}
}