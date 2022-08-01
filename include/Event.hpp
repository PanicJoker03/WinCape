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
	};
	using EventCallback = std::function<void(Event)>;
	template<typename T> using Reference = std::reference_wrapper<T>;
}
#endif // EVENT_HPP
