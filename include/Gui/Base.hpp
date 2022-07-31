#ifndef BASE_HPP
#define BASE_HPP
#include "defines.hpp"
namespace WinCape{
	namespace Gui{
		class Base : public HasHandle<WindowHandle>
		{
		public:
			void setText(const wchar_t* text);
			void getText(wchar_t* text, int lenght) const;
		protected:
			Base();
		};
	}
}
#endif
