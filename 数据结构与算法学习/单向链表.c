#include<stdio.h>
#include<stdlib.h>
#define E int

typedef struct List
{
	struct List* last;
	struct List* next;
	E  ele;

}list;

list* initlist()
{
	list* head = malloc(sizeof(list));
	head->ele = 0;
	head->next = NULL;
	head->last = NULL;
	return head;
}

void printlist(list* head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			head = head->next;
		else
		{
			printf("链表为空\n");
			return 0;
		}
	}
	else
	{
		printf("链表指针为空\n");
		return 0;
	}

	while (head != NULL)
	{
		printf("%d->", head->ele);
		head = head->next;
	}
	printf("打印完成\n");
}

void pushback(list* head, E tele)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			head = head->next;
		else
		{
			head->next = malloc(sizeof(list));
			head->next->last = head;
			head->next->next = NULL;
			head->next->ele = tele;
			return 0;
		}
	}
	else
	{
		printf("链表指针为空\n");
		return 0;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = malloc(sizeof(list));
	head->next->last = head;
	head->next->next = NULL;
	head->next->ele = tele;
	return 0;
}

void pushhead(list* head, E tele)
{
	if (head == NULL)
	{
		printf("链表指针为空\n");
		return 0;
	}
	if (head->next == NULL)
	{
		head->next = malloc(sizeof(list));
		head->next->last = head;
		head->next->ele = tele;
		head->next->next = NULL;
		return 0;
	}
	else
	{
		list* tp = head->next;
		head->next = malloc(sizeof(list));
		head->next->last = head;
		head->next->ele = tele;
		head->next->next = tp;
		head->next->next->last = head->next;
	}
}

void delettail(list* head)
{

	list* tp = head;
	while (head->next != NULL)
	{
		tp = head;
		head = head->next;
	}
	tp->next = NULL;
	free(head);
}

void delethead(list* head)
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
	list* tp = head->next;
	head->next = head->next->next;
	head->next->last = head;
	free(tp);
}

list* findone(list* head, E tele)
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
		if (head->ele == tele)
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

int main()
{
	list* head = initlist();

	//printlist(head);

	pushback(head, 3);
	pushback(head, 4);
	pushback(head, 5);
	pushhead(head, 8);
	//printf("%p", findone(head,7));


	return 0;
}
