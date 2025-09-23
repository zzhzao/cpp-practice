#pragma once
#include<vector>
#include<list>
#include<iostream>
#include<deque>
namespace zzh
{
	template<class T,class Container>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		const T& top() const
		{
			return _con.back();
		}
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}