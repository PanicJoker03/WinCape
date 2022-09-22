#include "Gui/Menu.hpp"
#include "Gui/GuiDefines.hpp"
#include "Gui/Manager.hpp"
namespace w_cape{
namespace usr
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
	void Menu::addSubMenu(usr::Menu& menu, WSTR_CON text)
	{
		AppendMenuW(
			handle(), MF_STRING | MF_POPUP, (UINT_PTR)menu.handle(), text
		);
	}
	void Menu::addItem(WSTR_CON item)
	{
		//Create MenuFlags in defines
		AppendMenuW(handle(), MF_STRING, 0, item);
	}
	//Omited at the moment
	//void Menu::addItems(std::initializer_list<WSTR_CON> itemList)
	//{
	//	for (WSTR_CON item : itemList)
	//	{
	//		addItem(item);
	//	}
	//}
	void Menu::onItemSelect(const EVE_CALL& callback)
	{
		usr::Manager::instance().listenEvent(
			(usr::Base::Handle)handle(), WindowMessages::MNU_CMD, callback
		);
	}
	void Menu::create(usr::Menu& menu)
	{
		MNU_HND menuHandle = CreateMenu();
		menu.handle(menuHandle);
		menu.enableMenuCommand();
	}
}}
