#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void menu()
{
	printf("*************************************\n");
	printf("************** 1.β�� ***************\n");
	printf("************** 2.βɾ ***************\n");
	printf("************** 3.ͷ�� ***************\n");
	printf("************** 4.ͷɾ ***************\n");
	printf("************** 5.���� ***************\n");
	printf("*************************************\n");

}

int main()
{
	int i = 0;
	int menu_num = 0;
	int push_num = 0;
	SL sl;
	SeqListInit(&sl);
	
	printf("��ѡ����Ҫ���еĲ���:");
	if(scanf("%d", &menu_num)==1)

	switch (menu_num)
	{
	case 1:
	{
		printf("������Ҫ���������");
		if (scanf("%d", &push_num) == 1)
		SeqListPushBack(&sl, push_num);
	}
		break;
	case 2:SeqListPopBack(&sl);
		break;
	case 3:
	{
		printf("������Ҫ���������");
		if(scanf("%d", &push_num)==1)
		SeqListPushFront(&sl, push_num);
	}
		break;
	case 4:SeqListPopFront(&sl);
		break;
	case 5: 
	{
		printf("������Ҫ���������");
		if (scanf("%d", &push_num) == 1)
		SeqListFind(&sl, push_num);
	}
		break;
	default:printf("�����������������");
		break;
	}
		
	
	return 0;
}