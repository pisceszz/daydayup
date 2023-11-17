 #define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	
	
	

}

test2()
{

}


int main()
{
	test1();

}