#ifndef COMBOBOX_H
#define COMBOBOX_H
//#include "defines.h"
#include "Ui/Control.h"
namespace w_cape{
namespace ui{
	class ComboBox : public Control
	{
	public:
		void addString(WCH_STR_CON string);
	};
}}
#endif
