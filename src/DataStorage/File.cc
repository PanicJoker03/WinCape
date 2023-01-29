#include "DataStorage/File.h"
#include <stdio.h>
namespace w_cape {
namespace dat_store{
	//https://ss64.com/nt/syntax-share-modes.html
	void dat_store::File::open(WSTR_CON filePath, DSRED_ACCES mode)
	{
		//TODO: Abrir con bandera OPEN_EXISTING

	}

	void dat_store::File::create(WSTR_CON filePath, DSRED_ACCES mode)
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

	void dat_store::File::truncate(WSTR_CON filePath)
	{
		//TODO: Abrir con bandera TRUNCATE_EXISTING y DRD_ACCES GenericWrite...
	}

	void dat_store::File::close()
	{

	}

	void dat_store::File::remove(WSTR_CON filePath)
	{

	}
}}
