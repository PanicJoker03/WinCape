#include "DataStorage/File.h"
#include <stdio.h>
namespace w_cape {
namespace dat_store{
	//https://ss64.com/nt/syntax-share-modes.html
	void dat_store::File::open(WCH_STR_CONST filePath, DSRED_ACCES mode)
	{
		//TODO: Abrir con bandera OPEN_EXISTING
		printf("abriendo archivo");
		FLL_HND hFile = CreateFileW(
			filePath,
			mode,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);
		if(hFile == INVALID_HANDLE_VALUE)
			throw "Error opening file";
		handle(hFile);
	}

	void dat_store::File::create(WCH_STR_CONST filePath, DSRED_ACCES mode)
	{
		//TODO: Abrir con bandera CREATE_NEW
		printf("creando archivo");
		FLL_HND hFile = CreateFileW(
			filePath,
			mode,
			FILE_SHARE_READ,
			NULL,
			CREATE_NEW,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);
		if(hFile == INVALID_HANDLE_VALUE)
			throw "Error creating file";
		handle(hFile);
	}

	void dat_store::File::truncate(WCH_STR_CONST filePath)
	{
		//TODO: Abrir con bandera TRUNCATE_EXISTING y DRD_ACCES GenericWrite...
	}

	void dat_store::File::close()
	{

	}

	void dat_store::File::remove(WCH_STR_CONST filePath)
	{

	}

	//void dat_store
}}
