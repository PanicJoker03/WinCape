#ifndef BASE_HPP
#define BASE_HPP

#include "defines.hpp"
#include "HasHandle.hpp"
namespace w_cape{
namespace usr{
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
