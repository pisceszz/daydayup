#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType;

//��̬˳���
typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;
}SL;

//�ӿں���
void SeqListInit(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps,SLDataType x);
void SeqListPopFront(SL* ps);
int  SeqListFind(SL* ps, SLDataType x);



