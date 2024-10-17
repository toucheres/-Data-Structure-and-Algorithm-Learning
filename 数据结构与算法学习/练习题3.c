//https://leetcode.cn/problems/rotate-list/description/

 // Definition for singly-linked list.
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

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
	if (k == 0)
	{
		return head;
	}

	struct ListNode* oldend = head;
	int leng = 1;
	while (oldend->next != NULL)
	{
		oldend = oldend->next;
		leng++;
	}

	k = k % leng;

	if (leng == 2)
	{
		if (k % 2 == 0)
		{
			return head;
		}
		struct ListNode* tp = head->next;
		head->next->next = head;
		head->next = NULL;
		return tp;
	}

	struct ListNode* start = head->next;
	if (start == NULL)
	{
		start = head;
	}
	struct ListNode* end = head;


	for (int i = 0; i < k; i++)
	{
		end = end->next;
		if (end == NULL)
		{
			end = head;
		}
	}
	start = end->next;
	if (start == NULL)
	{
		start = head;
	}
	end->next = NULL;
	oldend->next = head;
	return start;
}


struct ListNode* rotateRight1(struct ListNode* head, int k)
{
	if (head == NULL || head->next == NULL || k == 0)
	{
		return head;
	}

	struct ListNode* oldend = head;
	int length = 1;

	// 计算链表长度并找到尾节点
	while (oldend->next != NULL)
	{
		oldend = oldend->next;
		length++;
	}

	// 计算实际需要旋转的步数
	k = k % length;
	if (k == 0)
	{
		return head; // 如果旋转的步数等于链表长度，则不变
	}

	// 找到新的断点
	struct ListNode* newend = head;
	for (int i = 1; i < length - k; i++)  // 找到新尾节点
	{
		newend = newend->next;
	}

	struct ListNode* newhead = newend->next; // 新的头节点
	newend->next = NULL; // 断开旧链表
	oldend->next = head; // 连接尾部到原头

	return newhead; // 返回新的头节点
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
//10.43
//MB
//击败
//44.39 %