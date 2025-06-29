#define _CRT_SECURE_NO_WARNINGS 1
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array和array2没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去。
//	// 但是如果array2new的时候抛异常呢，就还需要套一层捕获释放逻辑，这里更好解决方案
//	// 是智能指针，否则代码太戳了
//	int* array1 = new int[10];
//	// try
//	int* array2 = new int[10]; // 抛异常呢
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Divide(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array1 << endl;
//		cout << "delete []" << array2 << endl;
//
//		delete[] array1;
//		delete[] array2;
//		throw; // 异常重新抛出，捕获到什么抛出什么
//	}
//	// ...
//	cout << "delete []" << array1 << endl;
//	delete[] array1;
//	cout << "delete []" << array2 << endl;
//	delete[] array2;
//}
//
//int main()
//{
//	try
//
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}




class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
	}
};

// 定制删除器
int main()
{
	// 定制删除方式，最好用shared_ptr，其次就是最好用lambda做删除器
	//
	std::shared_ptr<FILE> sp1(fopen("Test.cpp", "r"), Fclose());
	std::shared_ptr<FILE> sp2(fopen("Test.cpp", "r"), [](FILE* fp) {
		cout << "fclose:" << fp << endl;
		fclose(fp);
	});
	std::unique_ptr<FILE, Fclose> up1(fopen("Test.cpp", "r"));

	auto FcloseFunc = [](FILE* fp) {
		cout << "fclose:" << fp << endl;
		fclose(fp);
	};
	std::unique_ptr<FILE, decltype(FcloseFunc)> up3(fopen("Test.cpp", "r"), FcloseFunc);


	return 0;
}