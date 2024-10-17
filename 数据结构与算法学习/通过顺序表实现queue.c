#include<stdio.h>
#include<stdlib.h>

#define E int
#define err 31423

struct Queue
{
	E* arr;
	int capacity;
	int start;
	int end;
};

typedef struct Queue* queue;
_Bool initqueue(queue que, int sizeold)
{
	int size = sizeold + 1;
	que->arr = malloc(sizeof(E) * size);
	que->capacity = size;
	que->start = 0;
	que->end = 0;
	if (que->arr)
		return 1;
	else
	{
		return 0;
	}
}

//int getsize(queue que)
//{
//	if (que->end >= que->start)
//	{
//		return que->end - que->start;
//	}
//	else
//	{
//		return que->capacity - que->start + que->end;
//	}
//
//}

_Bool pushque(queue que, E ele)
{
	int tempend = que->end;
	que->end = (que->end + 1) % que->capacity;
	if (que->end == que->start)
	{
		printf("队列已满\n");
		que->end = tempend;
		return 0;
	}
	*(que->arr + que->end) = ele;
	return 1;
}

E popque(queue que)
{
	if (que->end == que->start)
	{
		printf("队列为空\n");
		return err;
	}
	E tp = *(que->arr + que->start+1);
	que->start++;
	return tp;
}

void printque(queue que)
{
	//int tempstart = que->start;
	//int index;
	for (int i=que->start;i!=que->end;1)
	{
		i = ((i + 1) % que->capacity);
		//index = (index + 1) % que->capacity;
		printf("%d->", *(que->arr+i));
	}
	printf("打印完成\n");
}

int main()
{
	struct Queue q;
	initqueue(&q, 5);
	for (int i = 0; i < 15; i++)
	{
		pushque(&q, i);
	}
	printque(&q);
	for (int i = 0; i < 3; i++)
	{
		popque(&q);
	}
	printque(&q);
	pushque(&q, 2334);
	printque(&q);
}