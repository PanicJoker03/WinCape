#ifndef MENU_HPP
#define MENU_HPP
#include "defines.hpp"
namespace WinCape {
	namespace Gui{
		class Window;
		class Menu final : public HasHandle<MenuHandle>
		{
		private:
			void enableMenuCommand();
		public:
			void addSubMenu(Menu& menu, const wchar_t* text);
			void addItem(const wchar_t* item);
			void addItems(std::initializer_list<const wchar_t*> itemList);
			void onItemSelect(const EventCallback& callback);
			static void create(Menu& menu);
			friend Window;
		};
	}
}
#endif
