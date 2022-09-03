#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP
//#include "defines.hpp"
#include "Gui/Control.hpp"
namespace cape{
namespace usr{
	class ComboBox : public Control
	{
	public:
		void addString(CON_WSTR string);
	};
}}
#endif
