#pragma once
#include<assert.h>
#include<iostream>

namespace zzh
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{ }
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n;i++)
			{
				push_back(val);
			}
		}
		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_finish = tmp + size();
				_start = tmp;
				_end_of_storage = _start + n;
			}
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return *(_start + i);
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		void insert(iterator pos,const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator it = _finish - 1;
			while (it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = x;
			++_finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}