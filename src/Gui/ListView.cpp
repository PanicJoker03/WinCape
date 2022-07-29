#include "defaults.hpp"
#include "defines.hpp"
#include "Gui/ListView.hpp"
#include "Manager.hpp"
namespace WinCape::Gui{
    int ListView::count(){
        return ListView_GetItemCount(handle());
    }

    void ListView::addColumn(int index, char* headerText, int width)
    {
        LVCOLUMNA column = {};
        column.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_MINWIDTH | LVCF_SUBITEM;
        column.fmt = LVCFMT_CENTER;
        column.pszText = headerText;
        column.cx = width > 0 ? width : Defaults::ListViewColumnWidth;
        column.cxMin = Defaults::ListViewMinColumnWidth;
        column.iSubItem = index;
        ListView_InsertColumn(handle(), index, &column);
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
        item.pszText = (char*)cols[0].c_str();
        ListView_InsertItem(handle(), &item);
        if(cols.size() > 1){
            for(size_t i = 1; i < cols.size(); i++){
                item.iSubItem = i;
                strcpy(item.pszText, cols[i].c_str());
                item.pszText = (char*)cols[i].c_str();
                ListView_SetItem(handle(), &item);
            }
        }
    }

    void ListView::addRow(int row, char * text){
        LV_ITEM item;
        item.mask = LVIF_TEXT;
        item.iItem = row;
        item.iSubItem = 0;
        item.pszText = text;
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
