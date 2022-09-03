#ifndef FILE_HPP
#define FILE_HPP
#include "DataStorage/DataStorageDefines.hpp"
#include "HasHandle.hpp"

namespace cape{
namespace dat{
	class File : public HasHandle<FLL_HND>
	{
	public:
		//Se omiten banderas de lpSecurityAttributes
		//Se omiten banderas de dwFlagsAndAttributes
		void open(CON_WSTR filePath, DRD_ACCES mode);//no usar OPEN_ALWAYS
		void create(CON_WSTR filePath, DRD_ACCES mode);//no usar CREATE_ALWAYS
		void truncate(CON_WSTR filePath);// usar GENERIC_WRITE por default
		void close();
		std::size_t size();
		//creation() must return date
		//lastAccess() must return date
		//lastWrite() must return date
		File copy(CON_WSTR newFile);
		void move(CON_WSTR newPath);
		//void replace(CON_WSTR replacePath); not sure of how to implement this
		static void remove(CON_WSTR filePath);
		static File copy(CON_WSTR from, CON_WSTR dest);
		static File move(CON_WSTR from, CON_WSTR dest);
		//static replace...
		//path
		//fullName
		//name
		//extension

		//write
		//read
	};
}}

#endif
