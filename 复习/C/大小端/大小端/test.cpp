//#include<iostream>
//using namespace std;
//union myunion
//{
//	int a;
//	char ch[4];
//};
//int main()
//{
//	myunion u;
//	u.a = 0x12345678;
//	if (u.ch[0] == 0x12)
//	{
//		cout << "´ó¶Ë";
//	}
//	else
//	{
//		cout << "Ð¡¶Ë";
//	}
//	return 0;
//}
#include<iostream>
#include<assert.h>
using namespace std;
int mystrlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

char* mystrcpy(char* dest, const char* src)
{
	if (dest == NULL && src == NULL)
	{
		return NULL;
	}
	char* start = dest;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return start;
}

char* mystrcat(char* dest, const char* src)
{
	if (dest == NULL && src == NULL)
	{
		return NULL;
	}
	char* start = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return start;
}

char* mtstrstr(char* str1, char* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	while (*str1 != '\0')
	{
		char* p1 = str1;
		char* p2 = str2;
		while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return str1;
		}
		str1++;
	}
	return NULL;
}

void* my_memcpy(void* dest, const void* src, size_t n)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char* p1 = (char*)dest;
	char* p2 = (char*)src;
	while (n--)
	{
		*p1++ = *p2++;
	}
	return dest;
}

void* my_memmove(void* dest, const void* src, size_t n)
{
	if (!dest || !src) return NULL;
	char* d = (char*)dest;
	const char* s = (const char*)src;
	if (d > s && d < s + n)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
		{
			*d = *s;
			d--;
			s--;
		}
	}
	else
	{
		while (n--)
		{
			*d = *s;
			d++;
			s++;
		}
	}
	return dest;
}