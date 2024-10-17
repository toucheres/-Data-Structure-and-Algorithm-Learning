#include"单向链表.h"
//使用单链表中的pushhead来替代push
//使用单链表中的delettail来替代pop
int main()
{
	list* head = NULL;
	initlist(&head);
	printlist(head);
	pushhead(head, 3);
	pushhead(head, 4);
	pushhead(head, 5);
	pushhead(head, 8);
	//printf("%p", findone(head,7));
	printlist(head);
	return 0;
}
