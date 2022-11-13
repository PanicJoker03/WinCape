#ifndef BASE_H
#define BASE_H

#include "defines.h"
#include "HasHandle.h"
namespace w_cape{
namespace ui{
	class Base : public HasHandle<WND_HND>
	{
	public:
		void setText(WSTR_CON text);
		void getText(PTR_WSTR text, int lenght) const;
	protected:
		Base();
	};
}}
#endif
