 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void reverse(char* str)
{
	char temp = *str;
	int len = my_strlen(str);
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if(my_strlen(str+1)>=2)
	    reverse(str + 1);
	*(str + len - 1) = temp;
}

int main()
{
	char arr[] = "abcdefg";
	reverse(arr);
	printf("%s", arr);
	
}