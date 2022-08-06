#ifndef MENU_HPP
#define MENU_HPP
#include "defines.hpp"
#include "HasHandle.hpp"
//Omited at the moment
//#include <initializer_list>
#include "Event.hpp"
namespace WinCape {
	namespace Gui{
		class Window;
		class Menu : public HasHandle<MenuHandle>
		{
		private:
			void enableMenuCommand();
		public:
			void addSubMenu(Menu& menu, const wchar_t* text);
			void addItem(const wchar_t* item);
			//Omited at the moment
            //void addItems(std::initializer_list<const wchar_t*> itemList);
			void onItemSelect(const EventCallback& callback);
			static void create(Menu& menu);
			friend Window;
		};
	}
}
#endif
