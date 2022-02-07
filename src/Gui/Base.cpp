#include "Gui/Base.hpp"
namespace WinCape::Gui
{
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(const TextChar* text)
	{
		SetWindowText(handle(), text);
	}
	void Base::getText(TextChar* text, int lenght) const
	{
		GetWindowText(handle(), text, lenght);
		//return text;
	}
}
