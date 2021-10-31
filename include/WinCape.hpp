#ifndef WINCAPE_HPP
#define WINCAPE_HPP
#include "defines.hpp"
#include "defaults.hpp"

//TODO...
//Use lower case on static methods
namespace WinCape
{

	struct Application;
	template<typename T> class HasHandle
	{
	public:
		using Handle = T;
		T handle() const;
		template<typename> friend class CanCreateFromResource;
	protected:
		HasHandle();
		void handle(const T& handle);
	private:
		T _handle;
	};
	namespace UserGui 
	{
		//forward declarations
		class Window;
		class Button;
		class RadioButton;
		class Menu;
		class Icon;
		class DeviceContext;
		class Bitmap;
		// Utility function...
		class Base : public HasHandle<WindowHandle>
		{
		public:
			void setText(const TextChar* text);
			void getText(TextChar* text, int lenght) const;
		protected:
			Base();
		};
		class Window : public Base
		{
		public:
			Window();
			Window(WindowHandle value);
			void show();
			void minimize();
			void addButton(Button& button, const TextChar* text, const Vector2I& position, const Vector2I& size = Defaults::ButtonSize);
			void addRadioButton(std::initializer_list<std::pair<Reference<RadioButton>, const wchar_t*>> radioButtonList, const Vector2I& position, const Vector2I& padding = Defaults::RadioButtonPadding);
			void attachMenu(Menu& menu);
			void onDestroy(const EventCallback& callback);
			void onPaint(const EventCallback& callback);
			void redraw();
			void close();
			void setIcon(const Icon& icon);
			DeviceContext deviceContext();
		};
		//enforce to this classes have to know nothing about Window class
		//add setFont function? (it may need a Font wrapper class, that can only be instantiated through ::new and returns a shared_ptr...)
		class Control : public Base
		{
		public:
			friend Window;
			void createFromResource(WindowHandle parent, int resource);
		};
		class Button : public Control
		{
		public:
			void onClick(const EventCallback& callback);

		};
		class RadioButton final : public Button
		{
		public:
			using Pair = std::pair<Reference<RadioButton>, const wchar_t*>;
		};
		class ComboBox final : public Control
		{
		public:
			void addString(const TextChar* string);
		};
		class ListBox final : public Control
		{
		public:
			void addString(const TextChar* string);
			int count();
		};
		class Menu final : public HasHandle<MenuHandle>
		{
		private:
			void enableMenuCommand();
		public:
			void addSubMenu(Menu& menu, const TextChar* text);
			void addItem(const TextChar* item);
			void addItems(std::initializer_list<const TextChar*> itemList);
			void onItemSelect(const EventCallback& callback);
			static void create(Menu& menu);
			friend Window;
		};
		class Icon final : public HasHandle<IconHandle>
		{
		public:
			Icon();
			void load(ResourceInt idi);
			friend Window;
		};
		class Bitmap final : public HasHandle<BitmapHandle>
		{
		private:
			Bitmap(const Bitmap&) = delete;
			//Bitmap& operator=(const Bitmap&) = delete;
			void getBitmapInfo(const DeviceContextHandle& deviceContext, BITMAPINFO& bmpInfo) const;
		public:
			Bitmap(const Vector2I& dimensions = Vector2I{});
			Bitmap& operator = (const Bitmap& bitmap);
			void load(const TextChar* sourcePath);
			Vector2I dimension() const;
			void clonePixels(void* buffer) const;
			void setPixels(void* buffer);
			~Bitmap();
		};
		/*class RenderContext final : public HasHandle<GlRenderContextHandle> {
		public:
			RenderContext();
			RenderContext(GlRenderContextHandle renderContext);
			friend Window;
		};*/
		class DeviceContext final : public HasHandle<DeviceContextHandle>
		{
		private:
			void bitBlt(BitmapHandle bitmapHandle, DeviceContextHandle destiny, const Rect& rect);
		public:
			DeviceContext();
			DeviceContext(DeviceContextHandle value);
			//void drawBitmap(const Bitmap& bitmap);
			void drawBitmap(const Bitmap& bitmap, const Vector2I& padding = Vector2I{});
			//drawBitmapClipped...
			//RenderContext createRenderContext();
			friend Window;
		};
		class Font final : public HasHandle<FontHandle>
		{
			//Do something...
		};
		//////////////////////////
		//High level abstraction//
		//////////////////////////
		class WindowFrame : public Window
		{
		private:
			const TextChar* windowName;
			const Rect rect;
			const WindowStyle style;
		protected:
			WindowFrame(const TextChar* windowName = Defaults::WindowName, const TextChar* title = Text("Default"), const Rect& rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
			virtual void onCreate() = 0;
			virtual void onDraw(DeviceContext& deviceContext) = 0;
			virtual void onDispose();
			virtual ~WindowFrame() = 0;
			friend Application;
		};
	}
	struct Application
	{
		/// <summary>
		/// Starts the application loop
		/// </summary>
		/// 
		static void init(const TextChar* name = Defaults::WindowName);
		static int run();
		static int run(WinCape::UserGui::WindowFrame& window);
		static InstanceHandle instance();
		//Really poor function, must be called at the application beginning in order to work...
		static void defaultFont(const TextChar* fontName);
		static UserGui::Window createWindow(const TextChar* windowName = Defaults::WindowName, const TextChar* title = Text("Default"), const Rect & rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
	};
}
#endif WINCAPE_HPP
