//https://leetcode.cn/problems/rotate-list/description/

 // Definition for singly-linked list.
#include<stdio.h>
#include<stdlib.h>
#include"��������.h"


//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//�ϰ�����������������֪Ϊ�ε�k�ܴ�ʱ��ʱ��
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

//����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�

// 
//
//ʾ�� 1��
//
//
//���룺head = [1, 2, 3, 4, 5], k = 2
//�����[4, 5, 1, 2, 3]
//ʾ�� 2��
//
//
//���룺head = [0, 1, 2], k = 4
//�����[2, 0, 1]
//
//
//��ʾ��
//
//�����нڵ����Ŀ�ڷ�Χ[0, 500] ��
//- 100 <= Node.val <= 100
//0 <= k <= 2 * 109


//����ֻͨ����һ��
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

//�ٴγ���,���ճɹ���ͷ���Ҫ�洢����(csdn�����ӵ�)
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

//ִ����ʱ�ֲ�
//0
//ms
//����
//100.00 %
//���Ӷȷ���
//�����ڴ�ֲ�
//10.40
//MB
//����
//58.90 %
