//https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
#include<stdio.h>


  //Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}
	if (head->next == NULL)
	{
		return head;
	}
	struct  ListNode* tphead = head;
	while (tphead->next != NULL)
	{
		if (tphead->val == tphead->next->val)
		{
			tphead->next = tphead->next->next;
			continue;
		}
		tphead = tphead->next;
	}
	return head;
}
//int main()
//{
//	return 0;
//}
 

//ִ����ʱ�ֲ�
//0
//ms
//����
//100.00 %
//���Ӷȷ���
//�����ڴ�ֲ�
//10.55
//MB
//����
//93.48 %
