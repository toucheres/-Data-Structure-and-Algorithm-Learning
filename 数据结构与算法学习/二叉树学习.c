#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
#include"MyQueueByLianBiao.h"

//�ڵ�Ķ���
typedef struct TreeNode
{
	E ele;
	struct TreeNode* left;
	struct TreeNode* right;
}* Node;

//ǰ�������ӡTree(�ݹ�)
void printTree_preOrder(Node root)
{
	if (!root)
	{
		return;		
	}
	printf("%c->",root->ele);
	printTree_preOrder(root->left);
	printTree_preOrder(root->right);
}

//���������ӡTree(�ݹ�)
void printTree_inOrder(Node root)
{
	if (!root)
	{
		return;
	}
	printTree_inOrder(root->left);
	printf("%c->", root->ele);
	printTree_inOrder(root->right);
}
//���������ӡTree(�ݹ�)
void printTree_postOrder(Node root)
{
	if (!root)
	{
		return;
	}
	printTree_postOrder(root->left);
	printf("%c->", root->ele);
	printTree_postOrder(root->right);
}

//�������
void printTree_postOrder(Node root,queue que)
{
	
	
}

 
int main()
{
	//�������Ľ���
	Node a = (Node)malloc(sizeof(struct TreeNode));
	Node b = (Node)malloc(sizeof(struct TreeNode));
	Node c = (Node)malloc(sizeof(struct TreeNode));
	Node d = (Node)malloc(sizeof(struct TreeNode));
	Node e = (Node)malloc(sizeof(struct TreeNode));
	a->ele = 'A';
	b->ele = 'B';
	c->ele = 'C';
	d->ele = 'D';
	e->ele = 'E';

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	d->left = NULL;//��ֹҰָ��
	d->right = NULL;
	e->left = NULL;
	e->right = NULL;	
	c->left = NULL;
	c->right = NULL;

	queue que = malloc(sizeof(queue));
	printTree_inOrder(a);


}