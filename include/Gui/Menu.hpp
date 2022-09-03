#ifndef MENU_HPP
#define MENU_HPP
#include "defines.hpp"
#include "HasHandle.hpp"
//Omited at the moment
//#include <initializer_list>
#include "Event.hpp"
namespace cape {
namespace usr{
	class Window;
	class Menu : public HasHandle<MNU_HND>
	{
	private:
		void enableMenuCommand();
	public:
		void addSubMenu(Menu& menu, CON_WSTR text);
		void addItem(CON_WSTR item);
		//Omited at the moment
        //void addItems(std::initializer_list<CON_WSTR> itemList);
		void onItemSelect(const EVE_CALL& callback);
		static void create(Menu& menu);
		friend Window;
	};
}}
#endif
