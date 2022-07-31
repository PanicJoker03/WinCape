#include "Gui/Base.hpp"
namespace WinCape::Gui
{
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(const wchar_t* text)
	{
		SetWindowTextW(handle(), text);
	}
	void Base::getText(wchar_t* text, int lenght) const
	{
		GetWindowTextW(handle(), text, lenght);
		//return text;
	}
}
