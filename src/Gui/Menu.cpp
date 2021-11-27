#include "Gui/Menu.hpp"
#include "Manager.hpp"
namespace WinCape{
	namespace Gui{
		//-------------------------------------------------------------------------
		//Menu
		//-------------------------------------------------------------------------
		void Gui::Menu::enableMenuCommand()
		{
			//Enabling WM_MENUCOMMAND
			//https://stackoverflow.com/questions/14916356/how-to-enable-popup-menu-to-communicate-with-wm-menucommand-instead-of-wm-comman
			MENUINFO menuInfo = {};
			menuInfo.cbSize = sizeof(MENUINFO);
			GetMenuInfo(handle(), &menuInfo);
			menuInfo.fMask = MIM_STYLE;
			menuInfo.dwStyle |= MNS_NOTIFYBYPOS;
			SetMenuInfo(handle(), &menuInfo);
		}
		void Gui::Menu::addSubMenu(Gui::Menu& menu, const TextChar* text)
		{
			AppendMenu(handle(), MF_STRING | MF_POPUP, (UINT_PTR)menu.handle(), text);
		}
		void Gui::Menu::addItem(const TextChar* item)
		{
			//Create MenuFlags in defines
			AppendMenu(handle(), MF_STRING, 0, item);
		}
		void Gui::Menu::addItems(std::initializer_list<const TextChar*> itemList)
		{
			for (const TextChar* item : itemList)
			{
				addItem(item);
			}
		}
		void Gui::Menu::onItemSelect(const EventCallback& callback)
		{
			Manager::instance().listenEvent((Gui::Base::Handle)handle(), WindowMessages::MenuCommand, callback);
		}
		void Gui::Menu::create(Gui::Menu& menu)
		{
			MenuHandle menuHandle = CreateMenu();
			menu.handle(menuHandle);
			menu.enableMenuCommand();
		}
	}
}
