
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int Num(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count += n & 1;
//		
//		
//		n  >>= 1;
//	}
//	return count;
//
//
//}

int Num( int n)
{
	int count = 0;
	while (n)
	{
		n &= n - 1;
		count ++;

	}
	return count;


}
int main()
{
    int input = 0;
	scanf("%d", &input);
	int ret = Num(input);
	printf("%d", ret);
	return 0;
}