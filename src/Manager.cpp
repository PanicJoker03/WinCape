#include <Manager.hpp>
#include <WinCape.hpp>
#include <Helper.hpp>
#include <map>
#include <vector>
using namespace std;
namespace WinCape
{
	//-------------------------------------------------------------------------
	//Implementation
	//-------------------------------------------------------------------------
	class ManagerImpl
	{
		using EventKey = pair<Handle, WindowMessage>;
		//Wrap in a class?
		using EventMap = map<EventKey, EventCallback>;
		EventMap eventMap;
		//use vector of unique_ptr?
		vector<void*> ptrPool;
	public:
		using EventKey = pair<Handle, WindowMessage>;
		//Wrap in a class?
		using EventMap = map<EventKey, EventCallback>;
		static ManagerImpl& Instance()
		{
			static ManagerImpl instance;
			return instance;
		}
		void* poolPtr(void* ptr)
		{
			ptrPool.push_back(ptr);
			return ptr;
		}
		//call on destructor?
		void freeMemory()
		{
			for (auto& ptr : ptrPool)
			{
				delete ptr;
			}
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
		void listenEvent(const Handle& handle, const WindowMessage& message, const EventCallback& callback)
		{
			eventMap[EventKey{ handle, message }] = callback;
		}
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			//TODO: abstract message processing
			switch (message)
			{
			case WindowMessages::Destroy:
				PostQuitMessage(0);
				break;
			case WindowMessages::Command:
			{
				Handle handle = (Handle)lParam;
				WindowMessage controlMessage = HIWORD(wParam);
				auto key = ManagerImpl::Instance().eventMap.find(EventKey{ handle, controlMessage });
				if (key != ManagerImpl::Instance().eventMap.end())
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
		void registerClass()
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
			RegisterClassEx(&windowClass);
			//return windowClass;
		}
		Handle createHandle(const char* className, const char* text, const WindowStyle& style, const Rect& rect, const Handle& parent)
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
	};
	//-------------------------------------------------------------------------
	//Forwarding
	//-------------------------------------------------------------------------
	Manager::Manager() {}
	Manager& Manager::Instance()
	{
		static Manager instance;
		return instance;
	}
	int Manager::startListening()
	{
		return ManagerImpl::Instance().startListening();
	}
	void Manager::listenEvent(const Handle& handle, const WindowMessage& message, const EventCallback& callback)
	{
		ManagerImpl::Instance().listenEvent(handle, message, callback);
	}
	void* Manager::poolMemory(void* ptr)
	{
		return ManagerImpl::Instance().poolPtr(ptr);
	}
	void Manager::registerClass()
	{
		ManagerImpl::Instance().registerClass();
	}
	Handle Manager::createHandle(const char* className, const char* text, const WindowStyle& style, const Rect& rect, const Handle& parent)
	{
		return ManagerImpl::Instance().createHandle(className, text, style, rect, parent);
	}
}