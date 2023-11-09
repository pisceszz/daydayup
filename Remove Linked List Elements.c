
 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

  struct ListNode 
  {
  int val;
  struct ListNode *next;
  };
 
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL, * tmp = head;
    while (tmp)
    {
        if (tmp->val == val)
        {
            if (tmp == head)
            {
                head = tmp->next;
                free(tmp);
                tmp = head;
            }
            else
            {
                prev->next = tmp->next;
                free(tmp);
                tmp = prev->next;
            }

        }

        else
        {
            prev = tmp;
            tmp = tmp->next;
        }


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
    n2->val = 2; n2->next = n3;
    n3->val = 6; n3->next = n4;
    n4->val = 3; n4->next = n5;
    n5->val = 6; n5->next = NULL;
    struct ListNode*n= removeElements(n1, 6);


}