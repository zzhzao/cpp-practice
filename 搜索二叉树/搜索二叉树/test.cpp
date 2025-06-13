#define _CRT_SECURE_NO_WARNINGS 1
#include"BSTree.h"
//int main()
//{
//	BSTree<string, string> dict;
//	//BSTree<string, string> copy = dict;
//	dict.Insert("left", "左边");
//	dict.Insert("right", "右边");
//	dict.Insert("insert", "插⼊");
//	dict.Insert("string", "字符串");
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.Find(str);
//		if (ret)
//		{
//			cout << "->" << ret->_value << endl;
//		}
//		else
//		{
//			cout << "⽆此单词，请重新输⼊" << endl;
//		}
//	}
//	return 0;
//}

int main()
{
	string arr[] = { "苹果", "西⽠", "苹果", "西⽠", "苹果", "苹果", "西⽠", "苹果", "⾹蕉", "苹果","⾹蕉" };
	BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
		countTree.Insert(str, 1);
		}
		else

		{
		ret->_value++;
		}
		}
		countTree.InOrder();
		return 0;
	}


