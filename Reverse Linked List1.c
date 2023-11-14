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
        struct ListNode* cur = head;
        struct ListNode* newhead = NULL;
        while (cur)
        {
            struct ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;

    }


int main()
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
    