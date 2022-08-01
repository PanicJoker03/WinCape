#ifndef HASHANDLE_HPP
#define HASHANDLE_HPP
namespace WinCape{
	template<typename T> class HasHandle
	{
	public:
		using Handle = T;
		T handle() const{
			return _handle;
		}
		template<typename> friend class CanCreateFromResource;
	protected:
		HasHandle(){};
		void handle(T handle){
			_handle = handle;
		};
	private:
		T _handle;
	};
}
#endif // HASHANDLE_HPP
