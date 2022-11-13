#ifndef CONTROL_H
#define CONTROL_H
//#include "defines.h"
#include "Ui/Base.h"
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
