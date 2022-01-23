#ifndef LISTBOX_HPP
#define LISTBOX_HPP
#include "defines.hpp"
#include "Gui/Control.hpp"
namespace WinCape
{
	namespace Gui{
		class ListBox final : public Control
		{
		public:
			void addString(const TextChar* string);
			int count();
		};
	}
}
#endif