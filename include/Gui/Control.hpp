#ifndef CONTROL_HPP
#define CONTROL_HPP
//#include "defines.hpp"
#include "Gui/Base.hpp"
namespace w_cape{
namespace usr{
	class Window;//for friend
	class Control : public Base
	{
	public:
		friend Window;
		void createFromResource(WND_HND parent, int resource);
	};
}}
#endif
