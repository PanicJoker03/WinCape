#include "Event.hpp"
namespace cape{
		capeEvent::Event(): handle(0), wparam(0), lparam(0){}
		capeEvent::Event(WND_HND handle, WPARAM wparam, LPARAM lparam):
                           handle(handle), wparam(wparam), lparam(lparam){}
}
