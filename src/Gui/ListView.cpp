#include "Gui/GuiDefaults.hpp"
#include "defines.hpp"
#include "Gui/ListView.hpp"
#include "Manager.hpp"
#include "Gui/Style.hpp"
namespace WinCape::Gui{
    int ListView::count(){
        return ListView_GetItemCount(handle());
    }

    void ListView::addColumn(int index, const char* headerText, int width)
    {
        LVCOLUMN column = {};
        column.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_MINWIDTH | LVCF_SUBITEM;
        column.fmt = LVCFMT_CENTER;

		//#ifdef _WIN32
		//wcscpy_s(column.pszText, wcsnlen_s(headerText  + 1, 256), headerText);
		//#else
		//wcscpy(column.pszText, headerText);
		//#endif
#ifdef _UNICODE
		wchar_t wc[256]{};
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, headerText, strnlen_s(headerText, 256), wc, strnlen_s(headerText, 256));
		column.pszText = wc;
#else
		column.pszText = const_cast<char*>(headerText);

#endif
        column.cchTextMax = 256;
        column.cx = width > 0 ? width : Gui::Defaults::ListViewColumnWidth;
        column.cxMin = Gui::Defaults::ListViewMinColumnWidth;
        column.iSubItem = index;
        SendMessage(handle(), LVM_INSERTCOLUMN, index, (LPARAM)&column);
    }

    LV_ITEM ListView::getItem(int index){
        LV_ITEM item;
        item.iItem = index;
        ListView_GetItem(handle(), &item);
        return item;
    }

    void ListView::addRow(int row, std::vector<std::string> cols){
        LV_ITEM item;
        item.mask = LVIF_TEXT;
        item.iItem = row;
        item.iSubItem = 0;
#ifdef _UNICODE
		wchar_t wc[256]{};
		const char * txt = cols[0].c_str();
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, txt, strnlen_s(txt, 256), wc, strnlen_s(txt, 256));
		item.pszText = wc;
#else
		item.pszText = const_cast<char*>(cols[0].c_str());
#endif
        item.cchTextMax = 256;
        ListView_InsertItem(handle(), &item);
        if(cols.size() > 1){
            for(size_t i = 1; i < cols.size(); i++){
#ifdef _UNICODE
				wchar_t wcItem[256]{};
				const char * txtItem = cols[i].c_str();
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, txtItem, strnlen_s(txtItem, 256), wcItem, strnlen_s(txtItem, 256));
				item.pszText = wcItem;
#else
				item.pszText = const_cast<char*>(cols[i].c_str());
#endif
				item.iSubItem = i;
                item.cchTextMax = 256;
                ListView_SetItem(handle(), &item);
            }
        }
    }

    void ListView::addRow(int row, const char * text){
		LV_ITEM item{};
        item.mask = LVIF_TEXT;
        item.iItem = row;
        item.iSubItem = 0;
#ifdef _UNICODE
		wchar_t wc[256]{};
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, text, strnlen_s(text, 256), wc, strnlen_s(text, 256));
		item.pszText = wc;
#else
		item.pszText = const_cast<char*>(text);
#endif
        item.cchTextMax = 256;
        ListView_SetItem(handle(), &item);
    }

    void ListView::addCheckBoxes(){
        ListView_SetExtendedListViewStyle(handle(), ListViewStyles::Extended::Checkboxes | ListViewStyles::Extended::FullRowSelect);
    }

    void ListView::onItemChecked(const EventCallback & callback){
        Manager::instance().listenEvent((Base::Handle)handle(), ListViewMessages::ItemChanged, callback);
    }

    void ListView::clear(){
        ListView_DeleteAllItems(handle());
    }

    int ListView::selectedRow(){
        return ListView_GetNextItem(handle(), -1, LVNI_SELECTED);
    }

    void ListView::setItemChecked(int index, bool checked){
        ListView_SetCheckState(handle(), index, checked);
    }
}
