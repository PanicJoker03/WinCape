#ifndef LISTBOX_HPP
#define LISTBOX_HPP
//#include "defines.hpp"
#include "Gui/Control.hpp"
namespace cape{
namespace usr{
	class ListBox : public Control
	{
	public:
		void addString(CON_WSTR string);
		int count();
	};
}}
#endif
