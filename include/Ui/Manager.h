#ifndef MANAGER_H
#define MANAGER_H
#include "defines.h"
#include "Ui/Base.h"
#include "Event.h"
#include "Ui/Style.h"
namespace w_cape{
namespace ui
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();

		void listenEvent(ui::Base::Handle handle, WND_MSG message,
				const EVE_CALL& callback);

		void unlistenEvent(ui::Base::Handle handle, WND_MSG message);
		void defaultFont(WSTR_CON fontName);
		FON_HND defaultFont();
		void registerClass(WSTR_CON name);

		ui::Base::Handle createHandle(WSTR_CON className,
				WSTR_CON text, WND_STY style, const CAPE_RECT& rect,
				ui::Base::Handle parent = ui::Base::Null, WND_STY exStyle = 0);

		static Manager& instance();
	};	
}}
#endif
