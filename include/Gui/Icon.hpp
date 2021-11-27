#ifndef ICON_HPP
#define ICON_HPP
#include "defines.hpp"
namespace WinCape
{
	namespace Gui{
		class Window;
		class Icon final : public HasHandle<IconHandle>
		{
		public:
			Icon();
			void load(ResourceInt idi);
			friend Window;
		};
	}
}
#endif
