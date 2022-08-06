#include "Event.hpp"
namespace WinCape{
		Event::Event(): handle(0), wparam(0), lparam(0){}
		Event::Event(WindowHandle handle, WPARAM wparam, LPARAM lparam):
                           handle(handle), wparam(wparam), lparam(lparam){}
}
