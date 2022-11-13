#include "Event.h"
namespace w_cape{
	capeEvent::capeEvent(): handle(0), wparam(0), lparam(0){}
	capeEvent::capeEvent(WND_HND handle, WPARAM wparam, LPARAM lparam):
						handle(handle), wparam(wparam), lparam(lparam){}
}
