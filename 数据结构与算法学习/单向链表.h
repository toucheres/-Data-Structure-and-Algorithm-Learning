#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define E int
typedef struct List
{
	struct List* last;
	struct List* next;
	E  ele;
}list;