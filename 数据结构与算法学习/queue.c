#include<stdio.h>
#include<stdlib.h>

#define E int

struct Queue
{
	E* arr;
	int capacity;
	int start;
	int end;
};

typedef struct Queue* queue;
_Bool initqueue(queue que, int size)
{
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

_Bool pushque(queue que, E ele)
{
	if (que->end - que->start == que->capacity +1)
	{
		printf("队列已满，无法加入\n");
		return 0;
	}
    
	*(que->arr + (que->end % que->capacity)) = ele;
	que->end++;
	return 1;
}

E popque(queue que)
{
	if (que->end == que->start)
	{
		printf("队列为空\n");
		return -1;
	}
	E tp = *(que->arr + que->start);
	que->start++;
	return tp;
}

void printque(queue que)
{
	if (que->end == que->start)
	{
		printf("队列为空\n");
		return;
	}
	for (int i = que->start; i < que->end; i++)
	{
		printf("%d->", *(que->arr + i));
	}
	printf("打印完成\n");
}

int main()
{
	struct Queue q;
	initqueue(&q, 3);
	for (int i = 15; i > 0; i--)
	{
		pushque(&q, i);
	}
	for (int i = 2; i > 0; i--)
	{
		printf("%d\n",popque(&q));
	}
	//printf("________\n");
	//for (int i = 1; i > 0; i--)
	//{
	//	pushque(&q, 100*i);
	//}
	//for (int i = 10; i > 0; i--)
	//{
	//	printf("%d\n", popque(&q));
	//}

}