#ifndef BASE_HPP
#define BASE_HPP
#include "defines.hpp"
namespace WinCape{
	namespace Gui{
		class Base : public HasHandle<WindowHandle>
		{
		public:
			void setText(const TextChar* text);
			void getText(TextChar* text, int lenght) const;
		protected:
			Base();
		};
	}
}
#endif
