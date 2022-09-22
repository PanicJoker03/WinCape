#ifndef LISTBOX_HPP
#define LISTBOX_HPP
//#include "defines.hpp"
#include "Ui/Control.hpp"
namespace w_cape{
namespace ui{
	class ListBox : public Control
	{
	public:
		void addString(WSTR_CON string);
		int count();
	};
}}
#endif
