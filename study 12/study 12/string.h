#pragma once
#include<iostream>
#include<assert.h>
#include<string.h>
namespace zzh
{

	class string
	{
	public:
	/*	string()
			:_str(new char[1] { '\0' })
			, _size(0)
			, _capacity(0)
		{

		}*/
		 
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();

		iterator end();
	
		iterator begin() const;

		iterator end() const;
	


		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}

		const char* c_str() const
		{
			return _str;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		size_t size() const;
		char& operator[](size_t i);
		const char& operator[](size_t i) const;
		void reserve(size_t n);

		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);

		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos = 0)const;
		size_t find(const char* str, size_t pos = 0)const;
		
		string substr(size_t pos = 0, size_t len = npos) const;
		//string(const string& s);
		//string& operator=(const string& s);
		string& operator=(string tmp);
		void clear();

		size_t capacity()const;

		bool operator<(const string& s) const;
		bool operator>(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;

		void swap(string& s);
		string(const string& s)
		{
			//string tmp(s._str);
			string tmp(s.begin(), s.end());
			swap(tmp);
		}
		
		template <class InputIterator>
		string(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

	private:
		char* _str;
		size_t _size = 0;
		size_t _capacity = 0;
	
	public:
		static const size_t npos;
	};
	std::ostream& operator<<(std::ostream& os, const string& s);
	std::istream& operator>>(std::istream& is, string& s);

}