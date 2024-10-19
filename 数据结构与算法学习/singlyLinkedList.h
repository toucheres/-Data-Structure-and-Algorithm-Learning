#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//#include"单向链表.c"
#define E int
struct ListNode
{
	struct ListNode* next;
	E  val;
};