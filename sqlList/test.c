#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void menu()
{
	printf("*************************************\n");
	printf("************** 1.尾加 ***************\n");
	printf("************** 2.尾删 ***************\n");
	printf("************** 3.头加 ***************\n");
	printf("************** 4.头删 ***************\n");
	printf("************** 5.查找 ***************\n");
	printf("*************************************\n");

}

int main()
{
	int i = 0;
	int menu_num = 0;
	int push_num = 0;
	SL sl;
	SeqListInit(&sl);
	
	printf("请选择需要进行的操作:");
	if(scanf("%d", &menu_num)==1)

	switch (menu_num)
	{
	case 1:
	{
		printf("请输入要插入的数字");
		if (scanf("%d", &push_num) == 1)
		SeqListPushBack(&sl, push_num);
	}
		break;
	case 2:SeqListPopBack(&sl);
		break;
	case 3:
	{
		printf("请输入要插入的数字");
		if(scanf("%d", &push_num)==1)
		SeqListPushFront(&sl, push_num);
	}
		break;
	case 4:SeqListPopFront(&sl);
		break;
	case 5: 
	{
		printf("请输入要插入的数字");
		if (scanf("%d", &push_num) == 1)
		SeqListFind(&sl, push_num);
	}
		break;
	default:printf("输入错误，请重新输入");
		break;
	}
		
	
	return 0;
}