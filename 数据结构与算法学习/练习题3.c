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

	// ���������Ȳ��ҵ�β�ڵ�
	while (oldend->next != NULL)
	{
		oldend = oldend->next;
		length++;
	}

	// ����ʵ����Ҫ��ת�Ĳ���
	k = k % length;
	if (k == 0)
	{
		return head; // �����ת�Ĳ������������ȣ��򲻱�
	}

	// �ҵ��µĶϵ�
	struct ListNode* newend = head;
	for (int i = 1; i < length - k; i++)  // �ҵ���β�ڵ�
	{
		newend = newend->next;
	}

	struct ListNode* newhead = newend->next; // �µ�ͷ�ڵ�
	newend->next = NULL; // �Ͽ�������
	oldend->next = head; // ����β����ԭͷ

	return newhead; // �����µ�ͷ�ڵ�
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
//10.43
//MB
//����
//44.39 %