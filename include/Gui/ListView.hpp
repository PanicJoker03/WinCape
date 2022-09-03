#ifndef LISTVIEW_HPP
#define LISTVIEW_HPP
//#include "defines.hpp"
#include "Gui/Control.hpp"
#include "Event.hpp"
#include <vector>
#include <string>
namespace cape{
namespace usr{
    class ListView : public Control
    {
    public:
        int count();
        void addColumn(int index, CON_STR headerText, int width = 0);
        LV_ITEM getItem(int index);
        void addRow(int row, std::vector<std::string> cols);
        void addRow(int row, CON_STR text);
        void setRow(int row, int col, CON_STR text);
        void addCheckBoxes();
        void onItemChecked(const EVE_CALL& callback);
        void clear();
        int selectedRow();
        void setItemChecked(int index, bool checked);
    };
}}
#endif // LISTVIEW_HPP
