#include "DataStorage/File.hpp"
#include <stdio.h>
namespace w_cape {
namespace dst{
	void dst::File::open(WSTR_CON filePath, DRD_ACCES mode)
	{
		//TODO: Abrir con bandera OPEN_EXISTING
		printf("abriendo archivo");
	}

	void dst::File::create(WSTR_CON filePath, DRD_ACCES mode)
	{
		//TODO: Abrir con bandera CREATE_NEW
	}

	void dst::File::truncate(WSTR_CON filePath)
	{
		//TODO: Abrir con bandera TRUNCATE_EXISTING y DRD_ACCES GenericWrite...
	}

	void dst::File::close()
	{

	}

	void dst::File::remove(WSTR_CON filePath)
	{

	}
}}
