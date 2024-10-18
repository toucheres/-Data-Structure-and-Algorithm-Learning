//https://leetcode.cn/problems/rotate-list/description/

 // Definition for singly-linked list.
#include<stdio.h>
#include<stdlib.h>
#include"单向链表.h"


//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//废案（重新生成链表，不知为何当k很大时超时）
//struct ListNode* rotateRight(struct ListNode* head, int k)
//{
//	if (head == NULL)
//	{
//		return head;
//	}
//	if (head->next == NULL)
//	{
//		return head;
//	}
//	if (k == 0)
//	{
//		return head;
//	}
//
//	struct ListNode* oldend = head;
//	int leng = 1;
//	while (oldend->next != NULL)
//	{
//		oldend = oldend->next;
//		leng++;
//	}
//
//	k = k % leng;
//
//	if (leng == 2)
//	{
//		if (k % 2 == 0)
//		{
//			return head;
//		}
//		struct ListNode* tp = head->next;
//		head->next->next = head;
//		head->next = NULL;
//		return tp;
//	}
//
//	struct ListNode* start = head->next;
//	if (start == NULL)
//	{
//		start = head;
//	}
//	struct ListNode* end = head;
//
//
//	for (int i = 0; i < k; i++)
//	{
//		end = end->next;
//		if (end == NULL)
//		{
//			end = head;
//		}
//	}
//	start = end->next;
//	if (start == NULL)
//	{
//		start = head;
//	}
//	end->next = NULL;
//	oldend->next = head;
//	return start;
//}

//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

// 
//
//示例 1：
//
//
//输入：head = [1, 2, 3, 4, 5], k = 2
//输出：[4, 5, 1, 2, 3]
//示例 2：
//
//
//输入：head = [0, 1, 2], k = 4
//输出：[2, 0, 1]
//
//
//提示：
//
//链表中节点的数目在范围[0, 500] 内
//- 100 <= Node.val <= 100
//0 <= k <= 2 * 109


//还是只通过了一半
//struct ListNode* rotateRight(struct ListNode* head, int k)
//{
//	if (head == NULL)
//	{
//		return head;
//	}
//	if (head->next == NULL)
//	{
//		return head;
//	}
//	if (head->next->next == NULL)
//	{
//		return head;
//	}
//	if (k == 0)
//	{
//		return head;
//	}
//
//	int num = 0;
//	struct ListNode* mmm = head->next;
//	struct ListNode* tail = head;
//	while (mmm != NULL)
//	{
//		tail = mmm;
//		mmm = mmm->next;
//		num++;
//	}
//	tail->next = head;
//	k = (k % num);
//	k = num - k;
//
//
//
//	struct ListNode* tphead = head->next;
//	struct ListNode* tpheadlast = head;
//
//	for (int i = 0; i < k; i++)
//	{
//		tpheadlast = tphead;
//		tphead = tphead->next;
//	}
//	tpheadlast->next = NULL;
//	head->next = tphead ;
//	return tphead;
//}

//再次尝试,最终成功，头结点要存储数据(csdn误人子弟)
struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (head == NULL)
	{
		return head;
	}
	if (head->next == NULL)
	{
		return head;
	}
	//if (head->next->next == NULL)
	//{
	//	return head;
	//}
	
	if (k == 0)
	{
		return head;
	}





	int num = 0;
	struct ListNode* mmm = head;
	struct ListNode* tail = NULL;
	while (mmm != NULL)
	{
		tail = mmm;
		mmm = mmm->next;
		num++;
	}
	tail->next = head;
	k = (k % num);
	k = num - k;

	//struct ListNode* orhead = head->next;
	while (k--)
	{
		head = head->next;
	}

	struct ListNode* tail2 = head;
	num -= 1;
	while (num--)
	{
		tail2 = tail2->next;
	}
	tail2->next = NULL;
	return head;
}


 
int main()
{

}

//执行用时分布
//0
//ms
//击败
//100.00 %
//复杂度分析
//消耗内存分布
//10.40
//MB
//击败
//58.90 %
