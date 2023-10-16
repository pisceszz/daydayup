#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print(int i)
{
	if (i > 9)
	{
		print(i / 10);
	}
		
	printf("%d ", i % 10);
}

int main()
{
	 int i = 0;
	scanf("%d", &i);
	print(i);
	return 0;
}