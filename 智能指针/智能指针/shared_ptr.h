#pragma once

#include<functional>
#include<atomic>

namespace zzh
{
	template<class T>
	class shared_ptr
	{
	public:
		template<class D>
		shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new atomic<int>(1))
			, _del(del)
		{
		}

		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new atomic<int>(1))
		{
		}

		// sp2(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		// sp1 = sp3
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

		void release()
		{
			if (--(*_pcount) == 0)
			{
				//delete _ptr;
				_del(_ptr);
				delete _pcount;
			}
		}

		~shared_ptr()
		{
			release();
		}

		// ָһʹ
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

		operator bool()
		{
			return _ptr != nullptr;
		}
	private:
		T* _ptr;
		//int* _pcount;
		atomic<int>* _pcount;

		function<void(T*)> _del = [](T* ptr) {delete ptr; };
	};
}