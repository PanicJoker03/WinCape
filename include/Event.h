#ifndef EVENT_H
#define EVENT_H
#include "defines.h"
#include <functional>
namespace w_cape{
	typedef struct capeEvent
	{
		WND_HND handle;
		WPARAM wparam;
		LPARAM lparam;
		capeEvent();
		capeEvent(WND_HND handle, WPARAM wparam, LPARAM lparam);
	}EVENT;
	//using EVE_CALL = std::function<void(EVENT)>;
	typedef void (*EVE_CALL)(const EVENT);
    //Omited at the moment
    //template<typename T> using Reference = std::reference_wrapper<T>;
}
#endif // EVENT_H
