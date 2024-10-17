//https://leetcode.cn/problems/reverse-linked-list/description/

//  Definition for singly-linked list.
#include<stdio.h>
#include<stdlib.h>
  struct ListNode {
     int val;
     struct ListNode *next;
  };
 
struct ListNode* reverseList(struct ListNode* head) 
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    struct ListNode* tphead = head;
    struct ListNode* oldhead = NULL;
    struct ListNode* newhead = NULL;
    while (tphead != NULL)
    {
        newhead = malloc(sizeof(struct ListNode));
        newhead->val = tphead->val;
        newhead->next = oldhead;
        oldhead = newhead;
        tphead = tphead->next;
    }
    return newhead;
}




//int main()
//{
//
//}

//ִ����ʱ�ֲ�
//0
//ms
//����
//100.00 %
//���Ӷȷ���
//�����ڴ�ֲ�
//10.75
//MB
//����
//5.03 %