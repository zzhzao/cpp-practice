#pragma once
#include<assert.h>
#include<iostream>
#include <initializer_list>
using namespace std;
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
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
		}
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
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
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
					//memcpy(tmp, _start, sizeof(T) * size());
					for (size_t i =0;i < size();i++)
					{
						tmp[i] = _start[i];
					}
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
		iterator insert(iterator pos, const T& x)
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
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			assert(pos >= _start);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}
		void resize(int n, T val = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}
		void resize(size_t n, T val = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}


	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}