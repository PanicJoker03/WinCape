#ifndef EVENT_HPP
#define EVENT_HPP
#include "defines.hpp"
#include <functional>
namespace WinCape{
	struct Event
	{
		WindowHandle handle;
		WPARAM wparam;
		LPARAM lparam;
		Event();
		Event(WindowHandle handle, WPARAM wparam, LPARAM lparam);
	};
	//using EventCallback = std::function<void(Event)>;
	typedef void (*EventCallback)(Event);
    //Omited at the moment
    //template<typename T> using Reference = std::reference_wrapper<T>;
}
#endif // EVENT_HPP
