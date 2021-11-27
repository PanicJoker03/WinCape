#ifndef RADIOBUTTON_HPP
#define RADIOBUTTON_HPP
#include "defines.hpp"
#include "Gui/Button.hpp"
namespace WinCape
{
	namespace Gui{
		class RadioButton final : public Button
		{
		public:
			using Pair = std::pair<Reference<RadioButton>, const TextChar*>;
		};
	}
}
#endif
