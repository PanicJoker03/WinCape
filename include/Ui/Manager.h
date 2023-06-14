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
		void defaultFont(WCH_STR_CONST fontName);
		FON_HND defaultFont();
		void registerClass(WCH_STR_CONST name);

		ui::Base::Handle createHandle(WCH_STR_CONST className,
				WCH_STR_CONST text, WND_STY style, const CAPE_RECT& rect,
				ui::Base::Handle parent = ui::Base::Null, WND_STY exStyle = 0);

		static Manager& instance();
	};	
}}
#endif
