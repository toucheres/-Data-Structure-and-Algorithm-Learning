#include"singlyLinkedList.h"
//#include<stdio.h>
//#include<stdlib.h>
//#define E int
//
//typedef struct struct ListNode
//{
//	struct struct ListNode* last;
//	struct struct ListNode* next;
//	E  val;
//
//}struct ListNode;

struct ListNode* initListNode(struct ListNode** phead)
{
	
	(*phead) = malloc(sizeof(struct ListNode));
	(*phead)->val = 0;
	(*phead)->next = NULL;
	
	return (*phead);
}

void printListNode(struct ListNode* head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			head = head->next;
		else
		{
			printf("链表为空\n");
			return ;
		}
	}
	else
	{
		printf("链表指针为空\n");
		return ;
	}

	while (head != NULL)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("打印完成\n");
}

void pushback(struct ListNode* head, E tval)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			head = head->next;
		else
		{
			head->next = malloc(sizeof(struct ListNode));
			
			head->next->next = NULL;
			head->next->val = tval;
			return ;
		}
	}
	else
	{
		printf("链表指针为空\n");
		return ;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = malloc(sizeof(struct ListNode));
	
	head->next->next = NULL;
	head->next->val = tval;
	return ;
}

void pushhead(struct ListNode* head, E tval)
{
	if (head == NULL)
	{
		printf("链表指针为空\n");
		return ;
	}
	if (head->next == NULL)
	{
		head->next = malloc(sizeof(struct ListNode));
		
		head->next->val = tval;
		head->next->next = NULL;
		return ;
	}
	else
	{
		struct ListNode* tp = head->next;
		head->next = malloc(sizeof(struct ListNode));
	
		head->next->val = tval;
		head->next->next = tp;

	}
}

void delettail(struct ListNode* head)
{

	struct ListNode* tp = head;
	while (head->next != NULL)
	{
		tp = head;
		head = head->next;
	}
	tp->next = NULL;
	free(head);
}

void delethead(struct ListNode* head)
{
	if (head == NULL)
	{
		printf("链表指针为空\n");
		return ;
	}
	if (head->next == NULL)
	{
		printf("链表为空\n");
		return ;
	}
	struct ListNode* tp = head->next;
	head->next = head->next->next;
	
	free(tp);
}

struct ListNode* findone(struct ListNode* head, E tval)
{
	if (head == NULL)
	{
		printf("链表指针为空\n");
		return 0;
	}
	if (head->next == NULL)
	{
		printf("链表为空\n");
		return 0;
	}
	while (head != NULL)
	{
		if (head->val == tval)
		{
			return head;
		}
		else
		{
			head = head->next;
		}
	}
	printf("未找到\n");
	return NULL;
}

//int main()
//{
//	struct ListNode* head = NULL;
//	initListNode(&head);
//
//	printListNode(head);
//
//	pushback(head, 3);
//	pushback(head, 4);
//	pushback(head, 5);
//	pushhead(head, 8);
//	printListNode(head);
//
//
//	return 0;
//}
