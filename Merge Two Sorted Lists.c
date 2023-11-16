 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

 struct ListNode {
      int val;
      struct ListNode *next;
  };
 
 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
 {
     struct ListNode* head, * tail;

     if (list1 == NULL)
         return list2;
     if (list2 == NULL)
         return list1;
     if (list1->val < list2->val)
     {
         head = tail = list1;
         list1 = list1->next;
     }

     else
     {
         head = tail = list2;
         list2 = list2->next;
     }
     while (list1 && list2)
     {
         if (list1->val < list2->val)
         {
             tail->next = list1;
             tail = list1;
             list1 = list1->next;
         }
         else
         {
             tail->next = list2;
             tail = list2;
             list2 = list2->next;
         }
     }
     if (list1)
     {
         tail->next = list1;
     }
     if (list2)
     {
         tail->next = list2;
     }
     return head;

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

 }
   
    