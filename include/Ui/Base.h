#ifndef BASE_H
#define BASE_H

#include "defines.h"
#include "HasHandle.h"
namespace w_cape{
namespace ui{
	class Base : public HasHandle<WND_HND>
	{
	public:
		void setText(WCH_STR_CON text);
		void getText(WCH_STR text, int lenght) const;
		void setProp(WCH_STR_CON prop, long val);
		void setProp(WCH_STR_CON prop, int val);
		void setProp(WCH_STR_CON prop, float val);
		//void setProp(WCH_STR_CON prop, double val);
		template<typename T>
		T getProp(WCH_STR_CON prop);
	protected:
		Base();
	};
}}
#endif
