#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "defines.hpp"
#include "Gui/Base.hpp"
#include "Event.hpp"
#include "Gui/Style.hpp"
namespace wcape{
namespace usr
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();

		void listenEvent(usr::Base::Handle handle, WND_MSG message,
				const EVE_CALL& callback);

		void unlistenEvent(usr::Base::Handle handle, WND_MSG message);
		void defaultFont(WSTR_CON fontName);
		FON_HND defaultFont();
		void registerClass(WSTR_CON name);

		usr::Base::Handle createHandle(WSTR_CON className,
				WSTR_CON text, WND_STY style, const CAPE_RECT& rect,
				usr::Base::Handle parent = usr::Base::Null, WND_STY exStyle = 0);

		static Manager& instance();
	};	
}}
#endif
