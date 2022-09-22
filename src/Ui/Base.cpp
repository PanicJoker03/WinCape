#include "Ui/Base.hpp"
namespace w_cape{
namespace ui{
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(WSTR_CON text)
	{
		SetWindowTextW(handle(), text);
	}
	void Base::getText(PTR_WSTR text, int lenght) const
	{
		GetWindowTextW(handle(), text, lenght);
		//return text;
	}
}}
