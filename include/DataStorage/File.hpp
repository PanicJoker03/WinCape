#ifndef FILE_HPP
#define FILE_HPP
#include "DataStorage/DataStorageDefines.hpp"
#include "HasHandle.hpp"
#include <cstddef>

namespace w_cape{
namespace dst{
	class File : public HasHandle<FLL_HND>
	{
	public:
		//Se omiten banderas de lpSecurityAttributes
		//Se omiten banderas de dwFlagsAndAttributes
		void open(WSTR_CON filePath, DRD_ACCES mode);//no usar OPEN_ALWAYS
		void create(WSTR_CON filePath, DRD_ACCES mode);//no usar CREATE_ALWAYS
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
		//read
	};
}}

#endif
