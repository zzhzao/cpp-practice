#pragma once
template<class Iterator, class Ref,class Ptr>

struct ReverseIterator
{
	typedef ReverseIterator<Iterator, Ref£¬Ptr> Self;
	ReverseIterator(Iterator it)
		:_it(it)
	{ }
	Ref operator*()
	{
		Iterator tmp;
		--tmp;
		return *tmp;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		--_it;
		return *this;
	}
	Self& operator--()
	{
		++_it;
		return *this;
	}
	Iterator _it;
};
