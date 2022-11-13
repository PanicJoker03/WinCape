#ifndef CONTROL_HPP
#define CONTROL_HPP
//#include "defines.hpp"
#include "Ui/Base.hpp"
namespace w_cape{
namespace ui{
	class Window;//for friend
	class Control : public Base
	{
	public:
		friend Window;
		void createFromResource(WND_HND parent, int resource);
	};
}}
#endif
