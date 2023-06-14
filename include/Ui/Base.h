#ifndef BASE_H
#define BASE_H

#include "defines.h"
#include "HasHandle.h"
namespace w_cape{
namespace ui{
	class Base : public HasHandle<WND_HND>
	{
	public:
		void setText(WCH_STR_CONST text);
		void getText(WCH_STR text, int lenght) const;
	protected:
		Base();
	};
}}
#endif
