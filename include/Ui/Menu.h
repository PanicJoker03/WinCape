#ifndef MENU_H
#define MENU_H
#include "defines.h"
#include "HasHandle.h"
//Omited at the moment
//#include <initializer_list>
#include "Event.h"
namespace w_cape {
namespace ui{
	class Window;
	class Menu : public HasHandle<MNU_HND>
	{
	private:
		void enableMenuCommand();
	public:
		void addSubMenu(Menu& menu, WSTR_CON text);
		void addItem(WSTR_CON item);
		//Omited at the moment
        //void addItems(std::initializer_list<WSTR_CON> itemList);
		void onItemSelect(const EVE_CALL& callback);
		static void create(Menu& menu);
		friend Window;
	};
}}
#endif
