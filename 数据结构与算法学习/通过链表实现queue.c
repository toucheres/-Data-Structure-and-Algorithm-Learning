#include"��������.h"
//ʹ�õ������е�pushhead�����push
//ʹ�õ������е�delettail�����pop
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
