#ifndef FILE_H
#define FILE_H
#include "DataStorage/DataStorageDefines.h"
#include "HasHandle.h"
#include <cstddef>

namespace w_cape{
namespace dat_store{
	class File : public HasHandle<FLL_HND>
	{
	public:
		//Se omiten banderas de lpSecurityAttributes
		//Se omiten banderas de dwFlagsAndAttributes
		void open(WCH_STR_CON filePath, DSRED_ACCES mode);//no usar OPEN_ALWAYS
		void create(WCH_STR_CON filePath, DSRED_ACCES mode);//no usar CREATE_ALWAYS
		void truncate(WCH_STR_CON filePath);// usar GENERIC_WRITE por default
		void close();
		std::size_t size();
		//creation() must return date
		//lastAccess() must return date
		//lastWrite() must return date
		File copy(WCH_STR_CON newFile);
		void move(WCH_STR_CON newPath);
		//void replace(WCH_STR_CON replacePath); not sure of how to implement this
		static void remove(WCH_STR_CON filePath);
		static File copy(WCH_STR_CON from, WCH_STR_CON dest);
		static File move(WCH_STR_CON from, WCH_STR_CON dest);
		//static replace...
		//path
		//fullName
		//name
		//extension

		//write
		bool write(WCH_STR_CON content, std::size_t* bytes_written);
		bool write(WCH_STR_CON content);
		//NEVER USE void*, force a stream object instead...
		//bool write(void* content, int* bytes_written);
		//bool write(void* content);
		//read
	};
}}

#endif
