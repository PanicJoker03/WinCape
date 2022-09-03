#include "DataStorage/File.hpp"
#include <stdio.h>
namespace cape {
namespace dat{
	void dat::File::open(CON_WSTR filePath, DRD_ACCES mode)
	{
		//TODO: Abrir con bandera OPEN_EXISTING
		printf("abriendo archivo");
	}

	void dat::File::create(CON_WSTR filePath, DRD_ACCES mode)
	{
		//TODO: Abrir con bandera CREATE_NEW
	}

	void dat::File::truncate(CON_WSTR filePath)
	{
		//TODO: Abrir con bandera TRUNCATE_EXISTING y DRD_ACCES GenericWrite...
	}

	void dat::File::close()
	{

	}

	void dat::File::remove(CON_WSTR filePath)
	{

	}
}}
