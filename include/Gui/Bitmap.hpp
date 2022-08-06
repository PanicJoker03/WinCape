#ifndef BITMAP_HPP
#define BITMAP_HPP
#include "defines.hpp"
#include "HasHandle.hpp"
namespace WinCape
{
	namespace Gui{
		class Bitmap : public HasHandle<BitmapHandle>
		{
		private:
			Bitmap(const Bitmap&);
			//Bitmap& operator=(const Bitmap&) = delete;
			void getBitmapInfo(const DeviceContextHandle& deviceContext,
					BITMAPINFO& bmpInfo) const;
		public:
			Bitmap(const Vector2I& dimensions = Vector2I());
			Bitmap& operator = (const Bitmap& bitmap);
			void load(const wchar_t* sourcePath);
			Vector2I dimension() const;
			void clonePixels(void* buffer) const;
			void setPixels(void* buffer);
			~Bitmap();
		};
	}
}
#endif
