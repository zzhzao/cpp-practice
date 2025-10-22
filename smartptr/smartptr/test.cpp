
#include<iostream>
using namespace std;
template<class T>
class smartptr
{
public:
	smartptr(T* ptr)
		:_ptr(ptr)
	{ }
	~smartptr()
	{
		cout << "~smartptr" << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};

int main()
{
	smartptr<int> ptr(new int[10]);

	return 0;
}