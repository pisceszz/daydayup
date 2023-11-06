 #define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	int newcapacity = 0;
	if (ps->size == ps->capacity)
	{
		newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	if (ps->size > 0)
		ps->size--;
	else printf("表中无数据");
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size-1;
	while (end--)
	{
		ps->a[end+1] = ps->a[end];
	}
	ps->a[0] = x;

}

void SeqListPopFront(SL* ps)
{
	if (ps->size > 0)
	{
		int begin = 0;
		for (begin = 0; begin < ps->size-1; begin++)
		{
			ps->a[begin] = ps->a[begin + 1];
		}
		ps->size--;
	}
	else printf("表中无数据");

}

int  SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			printf("找到了，%d", i);
		else printf("找不到");
	}

}

