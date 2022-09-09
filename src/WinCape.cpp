#include "defines.hpp"
#include "HasHandle.hpp"
#include "Application.hpp"

using namespace std;
namespace wcape
{
	//--------------------------------------------------------------------------
	//Avoiding template linkage errors
	//--------------------------------------------------------------------------
	template class HasHandle<WND_HND>;
	template class HasHandle<ICO_HND>;
	template class HasHandle<BMP_HND>;
	template class HasHandle<FON_HND>;
	template class HasHandle<DCX_HND>;
//#ifdef WINCAPE_USES_WGL
	template class HasHandle<GL_RCX_HND>;
//#endif
	template class HasHandle<MNU_HND>;
	template class HasHandle<ISC_HND>;	
	template class HasHandle<FLL_HND>;
}
