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
 

//执行用时分布
//0
//ms
//击败
//100.00 %
//复杂度分析
//消耗内存分布
//10.55
//MB
//击败
//93.48 %
