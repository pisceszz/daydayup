#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;

typedef struct SeqList {

	SLDataType data;
	struct SeqList* next;
}SL;


//SL*  SLBuy(SLDataType x);
void SLPushback(SL** pphead, SLDataType x);
SL* SLSeach(SL* pphead, SLDataType x);
void SLAdd(SL** pphead, SL* pose, SLDataType x);
void SLdelete(SL** pphead, SL* pose);
void SLPrint(SL* pphead);




