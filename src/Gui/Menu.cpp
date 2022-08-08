#include "Gui/Menu.hpp"
#include "Gui/GuiDefines.hpp"
#include "Gui/Manager.hpp"
namespace WinCape{
namespace Gui
{
	//--------------------------------------------------------------------------
	//Menu
	//--------------------------------------------------------------------------
	void Menu::enableMenuCommand()
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
	void Menu::addSubMenu(Gui::Menu& menu, const wchar_t* text)
	{
		AppendMenuW(
			handle(), MF_STRING | MF_POPUP, (UINT_PTR)menu.handle(), text
		);
	}
	void Menu::addItem(const wchar_t* item)
	{
		//Create MenuFlags in defines
		AppendMenuW(handle(), MF_STRING, 0, item);
	}
	//Omited at the moment
	//void Menu::addItems(std::initializer_list<const wchar_t*> itemList)
	//{
	//	for (const wchar_t* item : itemList)
	//	{
	//		addItem(item);
	//	}
	//}
	void Menu::onItemSelect(const EventCallback& callback)
	{
		Gui::Manager::instance().listenEvent(
			(Gui::Base::Handle)handle(), WindowMessages::MENU_COMMAND, callback
		);
	}
	void Menu::create(Gui::Menu& menu)
	{
		MenuHandle menuHandle = CreateMenu();
		menu.handle(menuHandle);
		menu.enableMenuCommand();
	}
}	}
