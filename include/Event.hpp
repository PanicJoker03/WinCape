#ifndef EVENT_HPP
#define EVENT_HPP
#include "defines.hpp"
#include <functional>
namespace cap{
	typedef struct capeEvent
	{
		WND_HND handle;
		WPARAM wparam;
		LPARAM lparam;
		capeEvent();
		capeEvent(WND_HND handle, WPARAM wparam, LPARAM lparam);
	}EVENT;
	//using EVE_CALL = std::function<void(EVENT)>;
	typedef void (*EVE_CALL)(EVENT);
    //Omited at the moment
    //template<typename T> using Reference = std::reference_wrapper<T>;
}
#endif // EVENT_HPP
