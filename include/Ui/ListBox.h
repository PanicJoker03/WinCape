#ifndef LISTBOX_H
#define LISTBOX_H
//#include "defines.h"
#include "Ui/Control.h"
namespace w_cape{
namespace ui{
	class ListBox : public Control
	{
	public:
		void addString(WCH_STR_CON string);
		int count() const;
	};
}}
#endif
