 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


 struct ListNode {
     int val;
     struct ListNode *next;
  };

 
  
 struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
     struct ListNode* slow, * fast;
     slow = fast = pHead;

     while (k--) {
         if (fast == NULL)
             return NULL;
         fast = fast->next;

     }

     while (fast) {
         slow = slow->next;
         fast = fast->next;
     }
     return slow;



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
   
    