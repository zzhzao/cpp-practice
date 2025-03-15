#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"

void menu() {
	//通讯录初始化 
	contact con;
	InitContact(&con);

	int op = -1;
	do {
		printf("********************************\n");
		printf("*****1、添加⽤⼾ 2、删除⽤⼾*****\n");
		printf("*****3、查找⽤⼾ 4、修改⽤⼾*****\n");
		printf("*****5、展⽰⽤⼾ 0、退出 *****\n");
		printf("********************************\n");
		printf("请选择您的操作：\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		default:
			printf("输⼊有误，请重新输⼊\n");
			break;
		}
	} while (op != 0);
	//销毁通讯录 
	DestroyContact(&con);
}
