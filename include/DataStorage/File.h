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
		void open(WSTR_CON filePath, DSRED_ACCES mode);//no usar OPEN_ALWAYS
		void create(WSTR_CON filePath, DSRED_ACCES mode);//no usar CREATE_ALWAYS
		void truncate(WSTR_CON filePath);// usar GENERIC_WRITE por default
		void close();
		std::size_t size();
		//creation() must return date
		//lastAccess() must return date
		//lastWrite() must return date
		File copy(WSTR_CON newFile);
		void move(WSTR_CON newPath);
		//void replace(WSTR_CON replacePath); not sure of how to implement this
		static void remove(WSTR_CON filePath);
		static File copy(WSTR_CON from, WSTR_CON dest);
		static File move(WSTR_CON from, WSTR_CON dest);
		//static replace...
		//path
		//fullName
		//name
		//extension

		//write
		bool write(WSTR_CON content, std::size_t* bytes_written);
		bool write(WSTR_CON content);
		//NEVER USE void*, force a stream object instead...
		//bool write(void* content, int* bytes_written);
		//bool write(void* content);
		//read
	};
}}

#endif
