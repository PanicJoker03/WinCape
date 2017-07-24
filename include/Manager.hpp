#include <defines.hpp>|
namespace WinCape
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();
		void listenEvent(const Handle& handle, const WindowMessage& message, const EventCallback& callback);
		void* poolMemory(void* ptr);
		void registerClass();
		Handle createHandle(const char* className, const char* text, const WindowStyle& style, const Rect& rect, const Handle& parent = NULL);
		static Manager& Instance();
	};
}