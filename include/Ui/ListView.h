#ifndef LISTVIEW_H
#define LISTVIEW_H
//#include "defines.h"
#include "Ui/Control.h"
#include "Event.h"
#include <vector>
#include <string>
namespace w_cape{
namespace ui{
    class ListView : public Control
    {
    public:
        int count();
        void addColumn(int index, STR_CON headerText, int width = 0);
        LV_ITEM getItem(int index);
        void addRow(int row, std::vector<std::string> cols);
        void addRow(int row, STR_CON text);
        void setRow(int row, int col, STR_CON text);
        void addCheckBoxes();
        void onItemChecked(const EVE_CALL& callback);
        void clear();
        int selectedRow();
        void setItemChecked(int index, bool checked);
    };
}}
#endif // LISTVIEW_H
