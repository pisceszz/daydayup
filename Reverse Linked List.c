 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


 struct ListNode {
     int val;
     struct ListNode *next;
  };

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* start1 = head;

    int i = 0;
    while (start1->next != NULL)
    {
        start1 = start1->next;
        i++;
    }
    struct ListNode* start = head;

    while (i > 1)
    {
        int j = 0;
        struct ListNode* end = start;
        for(j = 0; j <i; j++)
        {
            end = end->next;
        }
        int tmp = start->val;
        start->val = end->val;
        end->val = tmp;
        start = start->next;
        i -= 2;
    }
    return head;

}int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(n1 && n2 && n3 && n4 && n5);
    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = NULL;
    
   struct ListNode* head = reverseList(n1); 
    


    return 0;
}
    