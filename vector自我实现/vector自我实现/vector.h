#pragma once
#include<iostream>
namespace zzh
{
    template<class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
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
        vector()
            :_start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
        }
        vector(int n, const T& value = T())
        {
            resize(n, value);
        }

        template<class InputIterator>

        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*(first));
                first++;
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
        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }
        ~vector()
        {
            if (_start)
            {
                delete[] _start;
                _start = _finish = _endOfStorage = nullptr;
            }
        }

        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _endOfStorage - _start;
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t oldsize = size();
                T* tmp = new T[n];
                if (_start)
                {
                    for (int i = 0; i < size();i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + oldsize;
                _endOfStorage = _start + n;
            }
        }
        void resize(size_t n, const T& value = T())
        {
            if (n > size())
            {
                reserve(n);
                while (_start + n != _finish)
                {
                    *(_finish) = value;
                    _finish++;
                }
            }
            else
            {
                _finish = _start + n;
            }
        }

        T& operator[](size_t pos)
        {
            return *(_start + pos);
        }
        const T& operator[](size_t pos)const
        {
            return *(_start + pos);
        }
        void push_back(const T& x)
        {
            if (_finish == _endOfStorage)
            {
                int newcapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newcapacity);
            }
            *(_finish) = x;
            _finish++;
        }
        void pop_back()
        {
            assert(_start < _finish);
            _finish--;
        }
        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }

        iterator insert(iterator pos, const T& x)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            if (_finish == _endOfStorage)
            {
                int len = pos - _start;
                int newcapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newcapacity);
                pos = _start + len;
            }
            iterator end = _finish - 1;
            while (pos != end)
            {
                *(end + 1) = *(end);
                end--;
            }
            _finish++;
            *(pos) = x;
            return pos;
        }
        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos <= _finish);
            iterator it = pos + 1;
            while (it < _finish)
            {
                *(it - 1) = *(it);
            }
            _finish--;
            return pos;
        }
    private:
        iterator _start = nullptr; // 指向数据块的开始
        iterator _finish = nullptr; // 指向有效数据的尾
        iterator _endOfStorage = nullptr; // 指向存储容量的尾
    };
}