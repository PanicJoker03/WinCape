#ifndef ICON_H
#define ICON_H

#include "defines.h"
#include "HasHandle.h"
namespace w_cape{
namespace ui{
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
