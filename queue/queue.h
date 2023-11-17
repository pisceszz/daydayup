#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct QueueNode {

	DataType data;
	struct QueueNode* next;
}QN;

typedef struct Queue
{
	QN* head;
	QN* tail;
}Queue;


void QueueInit(Queue* Queue);
void QueueDstroy(Queue* Queue);
void QueuePush(Queue* Queue, DataType x);
void QueuePop(Queue* Queue);
void QueuePrint(Queue* Queue);

