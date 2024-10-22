using namespace std;
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
//#include"MyQueueByLianBiao.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // ��Ӧ stdlib.h
#include <cstring>  // ��Ӧ string.h
#include"singlyLinkedList.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
enum { preOrder, inOrder, postOrder };
// ������Ҫ�Ŀ�

//�ڵ�Ķ���
typedef struct TreeNode
{
	E ele;
	struct TreeNode* left;
	struct TreeNode* right;
	bool leftFlag;//��������ע
	bool rightFlag;//��������ע
}*Node;

//ǰ�������ӡTree(�ݹ�)
void printTree_preOrder(Node root)
{
	if (!root)
	{
		return;
	}
	printf("%c->", root->ele);
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

//
//�������
void printTree_tpOrder(Node root)
{
	std::queue<Node> que;
	que.push(root);
	while (1)
	{
		if (que.empty())
		{
			return;
		}
		if (que.front()->left != NULL)
		{
			que.push(que.front()->left);

		}
		if (que.front()->right != NULL)
		{
			que.push(que.front()->right);
		}
		printf("%c->", que.front()->ele);
		que.pop();
	}

}

void printTreeOrderly(Node root, int mode)
{
	switch (mode)
	{
	case preOrder:
		printTree_preOrder(root);
		break;
	case inOrder:
		printTree_inOrder(root);
		break;
	case postOrder:
		printTree_postOrder(root);
		break;
	default:
		printf("unknow mode\n");
		break;
	}
}
//----------------------------------
//������������
Node creatNodeThread()
{
	Node a = (Node)malloc(sizeof(struct TreeNode));
	if (a)
	{
		a->ele = 0;
		a->leftFlag = 0;
		a->rightFlag = 0;
		a->left = NULL;
		a->right = NULL;
	}
	else
	{
		printf("TreeNode����ʧ��\n");
	}
	return a;
}
void markThread(Node root, Node p)
{
	if (p && root)
	{
		if (root->left == NULL)
		{
			root->left = p;
			root->leftFlag = 1;
		}
		if (p->right == NULL)
		{
			p->right = root;
			p->rightFlag = 1;
		}
	}
}

Node pre = NULL;
void markThreadPreOrder(Node root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%c->", root->ele);
	}

	if (pre)
	{
		if (root->left == NULL)
		{
			root->left = pre;
			root->leftFlag = 1;
		}
		if (pre->right == NULL)
		{
			pre->right = root;
			pre->rightFlag = 1;
		}
	}
	pre = root;

	if (!root->leftFlag)
	{
		markThreadPreOrder(root->left);
	}
	if (!root->rightFlag)
	{
		markThreadPreOrder(root->right);
	}
}



void markThreadInOrder(Node root) {
	if (root == NULL) {
		return;
	}

	// �ݹ�������
	markThreadInOrder(root->left);

	// ����ǰ�ڵ�
	if (pre) {
		if (root->left == NULL) {
			root->left = pre; // ��ǰһ���ڵ�����Ϊ��ǰ�ڵ��������
			root->leftFlag = 1; // �������������
		}
		if (pre->right == NULL) {
			pre->right = root; // ����ǰ�ڵ�����Ϊǰһ���ڵ��������
			pre->rightFlag = 1; // �������������
		}
	}
	pre = root; // ����ǰһ���ڵ�Ϊ��ǰ�ڵ�
	printf("%c->", root->ele);

	// �ݹ�������
	markThreadInOrder(root->right);
}



void printThreadedTree_preOrder(Node root)
{
	if (root)
	{
		printf("%c->", root->ele);
		if (!root->leftFlag)
		{
			printThreadedTree_preOrder(root->left);
		}
		else
		{
			printThreadedTree_preOrder(root->right);
		}
		return;
	}
}

//void printThreadedTree_inOrder(Node root)
//{
//	if (!root)
//	{
//		return;
//	}
//	if (!root->leftFlag&&root->left)
//	{
//		printThreadedTree_inOrder(root->left);
//	}
//	
//	
//	printf("%c->", root->ele);		
//	
//	if (root->right)
//	{
//		
//		if (root->rightFlag)
//		{
//			// ����ָ��Ϊ�����ڵ㣬ֱ�Ӵ�ӡ
//			printf("%c->", root->right->ele);
//			return;
//		}
//		else
//		{
//			printThreadedTree_inOrder(root->right); // �ݹ����������
//		}
//	}
//	//return;
//}



/// �ص�------------------------------------------------

void printThreadedTree_inOrder(Node root)
{
	if (!root)
	{
		return;
	}

	// ����������ߵĽڵ�
	while (root->left && !root->leftFlag)
	{
		root = root->left;
	}

	// ֱ���ҵ��յ���߽�
	while (root)
	{
		// ��ӡ��ǰ�ڵ�
		printf("%c->", root->ele);

		// �����ָ����������ֱ����ת���ҽڵ�
		if (root->rightFlag)
		{
			root = root->right; // ��������ָ��Ľڵ�
		}
		else
		{
			// �����������������������
			root = root->right;

			// �����ҵ�����ߵĽڵ�
			while (root && root->left && !root->leftFlag)
			{
				root = root->left;
			}
		}
	}
}


void markThreadOrderly(Node root, int mode)
{
	switch (mode)
	{
	case preOrder:
		markThreadPreOrder(root);
		break;
	case inOrder:
		markThreadInOrder(root);
		break;
	case postOrder:
		//printThreadedTree_postOrder(root);
		break;
	default:
		printf("unknow mode\n");
		break;
	}
	pre = NULL;
}

void printThreadedTreeOrderly(Node root, int mode)
{
	switch (mode)
	{
	case preOrder:
		printThreadedTree_preOrder(root);
		break;
	case inOrder:
		printThreadedTree_inOrder(root);
		break;
	case postOrder:
		//printThreadedTree_postOrder(root);
		break;
	default:
		printf("unknow mode\n");
		break;
	}
}


int main()
{
	//�������Ľ���
	Node a = creatNodeThread();
	Node b = creatNodeThread();
	Node c = creatNodeThread();
	Node d = creatNodeThread();
	Node e = creatNodeThread();
	Node f = creatNodeThread();
	Node g = creatNodeThread();
	Node h = creatNodeThread();

	a->ele = 'A';
	b->ele = 'B';
	c->ele = 'C';
	d->ele = 'D';
	e->ele = 'E';
	f->ele = 'F';
	g->ele = 'G';
	h->ele = 'H';


	//			a
	//		b		c
	//  d	   e  f    g
	// h
	//
	//
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	d->left = h;



	
	//������������





	markThreadOrderly(a, inOrder);
	printf("\n");
	printThreadedTreeOrderly(a, inOrder);


	return 0;
}
