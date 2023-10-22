
#include<stdio.h>
#include<assert.h>
char * my_strcpy(char* str1, const char* str2)
{
    assert(str1&&str2);
    
    char* ret = str1;
    while (*str1++ = *str2++);
    return ret;

}
int main()
{
    char arr1[] = "abcdef";
    char arr2[20] = { 0 };

    my_strcpy(arr2, arr1);
    printf("%s", arr2);
}