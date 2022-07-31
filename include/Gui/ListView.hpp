#ifndef LISTVIEW_HPP
#define LISTVIEW_HPP
#include "defines.hpp"
#include "Gui/Control.hpp"
namespace WinCape{
    namespace Gui{
        class ListView final : public Control
        {
        public:
            int count();
            void addColumn(int index, const char* headerText, int width = 0);
            LV_ITEM getItem(int index);
            void addRow(int row, std::vector<std::string> cols);
            void addRow(int row, const char* text);
            void setRow(int row, int col, const char* text);
            void addCheckBoxes();
            void onItemChecked(const EventCallback& callback);
            void clear();
            int selectedRow();
            void setItemChecked(int index, bool checked);
        };
    }
}
#endif // LISTVIEW_HPP
