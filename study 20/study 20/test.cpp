#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

int main()
{
	zzh::stack<int, std::vector<int>> st;
	st.push(1);
	st.push(2);
	st.pop();

	return 0;
}