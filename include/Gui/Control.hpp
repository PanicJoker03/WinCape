#ifndef CONTROL_HPP
#define CONTROL_HPP
//#include "defines.hpp"
#include "Gui/Base.hpp"
namespace WinCape{
namespace Gui{
	class Window;//for friend
	class Control : public Base
	{
	public:
		friend Window;
		void createFromResource(WindowHandle parent, int resource);
	};
}}
#endif
