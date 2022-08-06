#ifndef FILE_HPP
#define FILE_HPP
#include "DataStorage/DataStorageDefines.hpp"
#include "HasHandle.hpp"
/*
namespace WinCape
{
	namespace DataStorage
	{
		class File : public HasHandle<FileHandle>
		{
		public:
		    //Se omiten banderas de lpSecurityAttributes
		    //Se omiten banderas de dwFlagsAndAttributes
		    void open(const wchar_t* filePath, DesiredAccess mode);//no usar OPEN_ALWAYS
		    void create(const wchar_t* filePath, DesiredAccess mode);//no usar CREATE_ALWAYS
		    void truncate(const wchar_t* filePath);// usar GENERIC_WRITE por default
		    void close();
		    std::size_t size();
		    //creation() must return date
		    //lastAccess() must return date
		    //lastWrite() must return date
		    File copy(const wchar_t* newFile);
		    void move(const wchar_t* newPath);
		    //void replace(const wchar_t* replacePath); not sure of how to implement this
		    static void delete(const wchar_t * filePath);
		    static File copy(const wchar_t* from, const wchar_t* dest);
		    static File move(const wchar_t* from, const wchar_t* dest);
		    //static replace...
		    //path
		    //fullName
		    //name
		    //extension

		    //write
		    //read
		};
	}
}
*/
#endif
