#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP
//#include "defines.hpp"
#include "Ui/Control.hpp"
namespace w_cape{
namespace ui{
	class ComboBox : public Control
	{
	public:
		void addString(WSTR_CON string);
	};
}}
#endif
