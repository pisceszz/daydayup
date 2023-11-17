 #define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

void QueueInit(Queue* Queue)
{
	assert(Queue);
	Queue->head = NULL;
	Queue->tail = NULL;
}

void QueueDstroy(Queue* Queue)
{
	assert(Queue);
	QN* cur = Queue->head;
	while (cur)
	{
		QN*next = cur->next;
		free(cur);
		cur = next;
	}
	Queue->head = Queue->tail = NULL;
}

void QueuePush(Queue* Queue, DataType x)
{
	assert(Queue);
	QN* newNode =(QN*)malloc(sizeof(QN));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
	}

	if (Queue->tail == NULL)
	{
		Queue->head = Queue->tail = newNode;
	}
	else
	{
		Queue->tail->next = newNode;
		Queue->tail = newNode;
	}


}
void QueuePop(Queue* Queue)
{
	assert(Queue && Queue->head);
	QN* cur = Queue->head;
	Queue->head = Queue->head->next;
	free(cur);
	if (Queue->head = NULL)//当全部数据删除后，tail可能是野指针
	{
		Queue->tail = NULL;
	}
}
void QueuePrint(Queue *Queue)
{
	QN* cur = Queue->head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
