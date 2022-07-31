#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP
#include "defines.hpp"
#include "Gui/Control.hpp"
namespace WinCape
{
	namespace Gui{
		class ComboBox final : public Control
		{
		public:
			void addString(const wchar_t* string);
		};
	}
}
#endif
