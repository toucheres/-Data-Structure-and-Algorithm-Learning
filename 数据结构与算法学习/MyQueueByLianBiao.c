
#include <malloc.h>
//使用单链表中的pushhead来替代push
//使用单链表中的delettail来替代pop
#include"MyQueueByLianBiao.h"



void initque(queue que)
{
	que->next = NULL;
	que->val = 0;
}

_Bool pushque(queue que, E ele)
{
	pushback(que, ele);
	return 1;
}

E popque(queue que)
{
	E tpe = que->next->val;
	delethead(que);
	return tpe;
}

queue seekque(queue que)
{
	return que->next;
}

_Bool isempty(queue que)
{
	if (que->next == NULL)
		return 1;
	return 0;
}
//int main()
//{
//	queue que = malloc(sizeof(queue));
//	initque(que);
//	pushque(que, 1);
//	pushque(que, 2);
//	pushque(que, 3);
//	printf("%d", popque(que));
//	printf("%d", popque(que));
//	printf("%d", popque(que));
//
//
//}