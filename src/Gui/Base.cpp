#include "Gui/Base.hpp"
namespace WinCape
{
	namespace Gui
	{
		//-------------------------------------------------------------------------
		//Base
		//-------------------------------------------------------------------------
		Gui::Base::Base() {}
		void Gui::Base::setText(const TextChar* text)
		{
			SetWindowText(handle(), text);
		}
		void Gui::Base::getText(TextChar* text, int lenght) const
		{
			GetWindowText(handle(), text, lenght);
			//return text;
		}
	}
}
