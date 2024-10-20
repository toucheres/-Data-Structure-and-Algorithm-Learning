#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//#include"单向链表.c"
#define E char
struct ListNode
{
	struct ListNode* next;
	E  val;
};
typedef struct ListNode* queue;

struct ListNode* initListNode(struct ListNode** phead);
void printListNode(struct ListNode* head);
void pushback(struct ListNode* head, E tval);
void pushhead(struct ListNode* head, E tval);
void delettail(struct ListNode* head);
void delethead(struct ListNode* head);
struct ListNode* findone(struct ListNode* head, E tval);
