#include "Gui/Base.hpp"
namespace cape{
namespace usr{
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(CON_WSTR text)
	{
		SetWindowTextW(handle(), text);
	}
	void Base::getText(WSTR_PTR text, int lenght) const
	{
		GetWindowTextW(handle(), text, lenght);
		//return text;
	}
}}
