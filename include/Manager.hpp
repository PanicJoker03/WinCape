#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "WinCape.hpp"
namespace WinCape
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();
		void listenEvent(UserGui::Base::Handle handle, WindowMessage message, const EventCallback& callback);
		void unlistenEvent(UserGui::Base::Handle handle, WindowMessage message);
		void defaultFont(const TextChar* fontName);
		FontHandle defaultFont();
		void registerClass(const TextChar* name);
		UserGui::Base::Handle createHandle(const TextChar* className, const TextChar* text, WindowStyle style, const Rect& rect, UserGui::Base::Handle parent = nullptr);
		static Manager& instance();
	};
}
#endif