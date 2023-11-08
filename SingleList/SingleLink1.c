 #define _CRT_SECURE_NO_WARNINGS
#include"SinglLink.h"


SL* SLBuy(SLDataType x)
{
	SL* newNode =(SL*)malloc(sizeof(SL));
	if (newNode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;

	}
	

	return newNode;
}


void SLPushback(SL** pphead, SLDataType x)
{
	
	SL* newNode = SLBuy(x);

	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SL* tmp = *pphead;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}	
}
void SLPrint(SL* pphead)
{
	SL* tmp = pphead;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");

}

SL* SLSeach(SL* pphead, SLDataType x)
{
	
	SL* tmpa = pphead;
	while (tmpa)
	{
		if (tmpa->data == x)
			return tmpa;
		else tmpa = tmpa->next;
	}
	return NULL;
}
void SLAdd(SL** pphead, SL* pose,SLDataType x) 
{
	assert(*pphead!=NULL);
	
	SL* newNode = SLBuy(x);
	SL* tmp = *pphead;
	if (*pphead == pose)
	{
		newNode->next = pose;
		*pphead = newNode;
	}
	else 
	{
		while (tmp->next != pose)
		{

			tmp = tmp->next;
		}
		newNode->next = pose;
		tmp->next = newNode;
	}
	

	
}
void SLdelete(SL** pphead, SL* pose) 
{
	if (*pphead == pose)
	{
		*pphead = pose->next;
		free(pose);
		pose = NULL;
	}
	else 
	{
		SL* tmp = *pphead;
		while (tmp->next != pose)
		{
			tmp = tmp->next;
		}
		tmp->next = pose->next;
		free(pose);
		pose = NULL;
	}
	
}

	



