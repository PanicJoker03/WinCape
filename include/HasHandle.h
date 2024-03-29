#ifndef HASHANDLE_H
#define HASHANDLE_H
namespace w_cape{
	template<typename T> 
    class HasHandle
	{
	public:
		typedef T Handle;
	
		static const T Null;
    	T handle() const{           
        	return _handle;
        }
        
		template<typename> 
        friend class CanCreateFromResource;
        
	protected:
		HasHandle(){}
		void handle(T handle){
        	_handle = handle;
		};
             
	private:
		T _handle;
    };
		
    template<typename T> 
    const T HasHandle<T>::Null = 0;
}
#endif // HASHANDLE_H
