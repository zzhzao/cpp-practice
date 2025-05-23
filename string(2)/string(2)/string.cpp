#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
namespace zzh {
	const size_t string::npos = -1;
	string::string(const char* str)
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;
		memcpy(_str, str, _size + 1);
	}
	string::string(const string& s)
	{
		_size = s._size;
		_capacity = s._capacity;
		_str = new char[_capacity + 1];
		memcpy(_str, s._str, _size + 1);
	}
	string& string::operator=(const string& s)
	{
		if (this != &s)
		{
			char* tmp = new char[s._capacity + 1];
			memcpy(tmp, s._str, s._size + 1);
			_str = tmp;
			delete[] _str;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	string:: ~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	void string::push_back(char c)
	{
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			//_str = new char[newcapacity + 1];
			//_capacity = newcapacity;
			reserve(newcapacity);
		}
		_str[_size++] = 'c';
		_str[_size] = '/0';
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			memcpy(tmp, _str, _size + 1);
			delete[] _str;
			_str = tmp;
			_capacity = n;

		}
	}
	string& string::operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = 2 * _capacity > _size + len ? 2 * _capacity : _size + len;
			reserve(newcapacity);
		}
		memcpy(_str + _size, str, len + 1);
		_size += len;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void string::clear()
	{
		_str[0] = '/0';
		_size = 0;
	}
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	const char* string::c_str()const
	{
		return _str;
	}
	size_t string::size()const
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}
	bool string::empty()const
	{
		if (_size == 0)
			return true;
		else
			return false;
	}
	void string::resize(size_t n, char c = '\0')
	{
		if (n < _size)
		{
			_size = n;
			_str[n + 1] = '\0';
		}
		else
		{
			if (n + _size > _capacity)
			{
				size_t newcapacity = 2 * _capacity > n + _size ? 2 * _capacity : n + _size;
				reserve(newcapacity);
			}
			while (_size != n)
			{
				_str[_size++] = '\0';
			}
			_str[_size + 1] = '\0';
		}
	}
	char& string::operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}
	const char& string::operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}
	bool string::operator<(const string& s)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < s._size)
		{
			if (_str[i1] < s._str[i2])
				return true;
			else if (_str[i1] > s._str[i2])
				return false;
			else
			{
				i1++;
				i2++;
			}
		}
		return i2 < s._size;
	}
	bool string::operator==(const string& s)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < s._size)
		{
			if (_str[i1] != s[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		return i1 == _size && i2 == s._size;
	}
	bool string::operator<=(const string& s)
	{
		return *this < s || *this == s;
	}
	bool string::operator>(const string& s)
	{
		return !(*this <= s);
	}
	bool string::operator>=(const string& s)
	{
		return !(*this < s);
	}
	bool string::operator!=(const string& s)
	{
		return !(*this == s);
	}
	size_t string::find(char c, size_t pos = 0) const
	{
		size_t i = 0;
		for (i = pos; i < _size;i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}
	size_t string::find(const char* s, size_t pos = 0) const
	{
		const char* p1 = strstr(_str + pos, s);
		if (p1 == nullptr)
			return npos;
		else
			return p1 - _str;
	}
	string& string::insert(size_t pos, char c)
	{
		assert(pos <= _size);

		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = c;
		_size++;
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = 2 * _capacity > _size + len ? 2 * _capacity : _size + len;
			reserve(newcapacity);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		for (int i = 0;i < pos;i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;
		return *this;
	}
	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len == npos || pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t i = pos + len;
			memmove(_str + pos, _str + i, _size + 1 - i);
			_size -= len;
		}
		return *this;
	}
};



