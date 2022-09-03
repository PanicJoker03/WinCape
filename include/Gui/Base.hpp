#ifndef BASE_HPP
#define BASE_HPP

#include "defines.hpp"
#include "HasHandle.hpp"
namespace cape{
namespace usr{
	class Base : public HasHandle<WND_HND>
	{
	public:
		void setText(CON_WSTR text);
		void getText(WSTR_PTR text, int lenght) const;
	protected:
		Base();
	};
}}
#endif
