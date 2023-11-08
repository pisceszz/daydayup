 #define _CRT_SECURE_NO_WARNINGS
#include"SinglLink.h"
void test1()
{
	SL* Plist = NULL;
	SLPushback(&Plist, 1);
	SLPushback(&Plist, 2);
	SLPushback(&Plist, 3);
	SLPushback(&Plist, 4);
	SLPushback(&Plist, 5);
	SLPushback(&Plist, 6);
	SLPrint(Plist);
}

void test2()
{

	SL* Plist = NULL;
	SLPushback(&Plist, 1);
	SLPushback(&Plist, 2);
	SLPushback(&Plist, 3);
	SLPushback(&Plist, 4);
	SLPushback(&Plist, 5);
	SLPushback(&Plist, 6);
	SLPushback(&Plist, 7);
	SLPushback(&Plist, 4);
	SLPushback(&Plist, 4);
	SLPushback(&Plist, 4);


	SLPrint(Plist);
	SL* pose = SLSeach(Plist, 4);
	int i = 1;
	while (pose)
	{
		printf("第%d个pose的地址是%p->%d\n", i++, pose, pose->data);
		pose = SLSeach(pose->next, 4);

	}
}
void test3()
	{
		SL* Plist = NULL;
		SLPushback(&Plist, 1);
		SLPushback(&Plist, 2);
		SLPushback(&Plist, 3);
		SLPushback(&Plist, 4);
		SLPushback(&Plist, 5);
		SLPushback(&Plist, 6);
		SLPrint(Plist);

		SL*pose = SLSeach(Plist, 1);
		SLAdd(&Plist, pose, 70);
		SLPrint(Plist);

		pose = SLSeach(Plist, 70);
		SLdelete(&Plist, pose);
		SLPrint(Plist);

			

	}



	


int main()
{
	//test1();
	//test2();
	test3();



}