#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP
//#include "defines.hpp"
#include "Gui/Control.hpp"
namespace wcape{
namespace usr{
	class ComboBox : public Control
	{
	public:
		void addString(WSTR_CON string);
	};
}}
#endif
