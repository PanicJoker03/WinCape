#ifndef ICON_HPP
#define ICON_HPP

#include "defines.hpp"
#include "HasHandle.hpp"
namespace cap{
namespace usr{
	class Window;
	class Icon : public HasHandle<ICO_HND>
	{
	public:
		Icon();
		void load(RESRC_I idi);
		friend Window;
	};
}}
#endif
