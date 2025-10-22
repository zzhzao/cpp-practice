#pragma once
namespace zzh
{
	template<class T>
	class shared_ptr
	{
	public:
		template<class D>
		shared_ptr(T* ptr = nullptr,D del)
			:_ptr(ptr)
			,_pcount(new int(1))
			,_del(del)
		{

		}
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			,_pcount(sp._pcount)
		{
			(*_pcount)++;
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
			}

			return *this;
		}
		~shared_ptr()
		{
			release();
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T* get()
		{
			return _ptr;
		}
		int use_count()
		{
			return *_pcount;
		}
		void release()
		{
			if (--(*_pount) == 0)
			{
				del(_ptr);
				delete _pcount;
			}
		}
	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) {delete ptr; };
	};
}