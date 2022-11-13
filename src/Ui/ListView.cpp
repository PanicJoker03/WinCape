#include "Ui/UiDefaults.hpp"
#include "defines.hpp"
#include "Ui/ListView.hpp"
#include "Ui/Manager.hpp"
#include "Ui/Style.hpp"
namespace w_cape{
namespace ui{
    int ListView::count(){
        return ListView_GetItemCount(handle());
    }

    void ListView::addColumn(int index, STR_CON headerText, int width)
    {
        LVCOLUMN col = {};
        col.mask = LVCF_FMT | 
			LVCF_TEXT | LVCF_WIDTH | LVCF_MINWIDTH | LVCF_SUBITEM;
        col.fmt = LVCFMT_CENTER;

		//#ifdef _WIN32
		//wcscpy_s(column.pszText, wcsnlen_s(headerText  + 1, 256), headerText);
		//#else
		//wcscpy(column.pszText, headerText);
		//#endif
#ifdef _UNICODE
		wchar_t wc[256]{};
		MultiByteToWideChar(
			CP_ACP, 
			MB_PRECOMPOSED, 
			headerText, 
			strnlen_s(headerText, 256), wc, strnlen_s(headerText, 256));
		col.pszText = wc;
#else
		col.pszText = const_cast<char*>(headerText);

#endif
        col.cchTextMax = 256;
        col.cx = width > 0 ? width : ui::Defaults::LIST_VIEW_COLUMN_WIDTH;
        col.cxMin = ui::Defaults::LIST_VIEW_MIN_COLUMN_WIDTH;
        col.iSubItem = index;
        SendMessage(handle(), LVM_INSERTCOLUMN, index, (LPARAM)&col);
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
		MultiByteToWideChar(
			CP_ACP, 
			MB_PRECOMPOSED, txt, strnlen_s(txt, 256), wc, strnlen_s(txt, 256));
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
				MultiByteToWideChar(
					CP_ACP, 
					MB_PRECOMPOSED, 
					txtItem, 
					strnlen_s(txtItem, 256), wcItem, strnlen_s(txtItem, 256));
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

    void ListView::addRow(int row, STR_CON text){
		LV_ITEM item;
        item.mask = LVIF_TEXT;
        item.iItem = row;
        item.iSubItem = 0;
#ifdef _UNICODE
		wchar_t wc[256]{};
		MultiByteToWideChar(
			CP_ACP, 
			MB_PRECOMPOSED, 
			text, strnlen_s(text, 256), wc, strnlen_s(text, 256));
		item.pszText = wc;
#else
		item.pszText = const_cast<char*>(text);
#endif
        item.cchTextMax = 256;
        ListView_SetItem(handle(), &item);
    }

    void ListView::addCheckBoxes(){
        ListView_SetExtendedListViewStyle(
			handle(), 
			ListViewStyles::Extended::CHECKBOXES | 
			ListViewStyles::Extended::FUL_ROW_SEL);
    }

    void ListView::onItemChecked(const EVE_CALL & callback){
        ui::Manager::instance().listenEvent(
			(Base::Handle)handle(), ListViewMessages::ITM_CHA, callback);
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
}}
