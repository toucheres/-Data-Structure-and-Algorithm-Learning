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
#include <cstdlib>  // 对应 stdlib.h
#include <cstring>  // 对应 string.h
#include"singlyLinkedList.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
enum { preOrder, inOrder, postOrder };
// 其他需要的库

//节点的定义
typedef struct TreeNode
{
	E ele;
	struct TreeNode* left;
	struct TreeNode* right;
	bool leftFlag;//线索化标注
	bool rightFlag;//线索化标注
}*Node;

//前序遍历打印Tree(递归)
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

//中序遍历打印Tree(递归)
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
//后序遍历打印Tree(递归)
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
//层序遍历
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
//线索化二叉树
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
		printf("TreeNode生成失败\n");
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

	// 递归左子树
	markThreadInOrder(root->left);

	// 处理当前节点
	if (pre) {
		if (root->left == NULL) {
			root->left = pre; // 将前一个节点设置为当前节点的左线索
			root->leftFlag = 1; // 设置左线索标记
		}
		if (pre->right == NULL) {
			pre->right = root; // 将当前节点设置为前一个节点的右线索
			pre->rightFlag = 1; // 设置右线索标记
		}
	}
	pre = root; // 更新前一个节点为当前节点
	printf("%c->", root->ele);

	// 递归右子树
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
//			// 若右指针为线索节点，直接打印
//			printf("%c->", root->right->ele);
//			return;
//		}
//		else
//		{
//			printThreadedTree_inOrder(root->right); // 递归遍历右子树
//		}
//	}
//	//return;
//}



/// 重点------------------------------------------------

void printThreadedTree_inOrder(Node root)
{
	if (!root)
	{
		return;
	}

	// 遍历到最左边的节点
	while (root->left && !root->leftFlag)
	{
		root = root->left;
	}

	// 直到找到空的左边界
	while (root)
	{
		// 打印当前节点
		printf("%c->", root->ele);

		// 如果右指针是线索，直接跳转到右节点
		if (root->rightFlag)
		{
			root = root->right; // 跳到线索指向的节点
		}
		else
		{
			// 否则进到右子树，继续查找
			root = root->right;

			// 继续找到最左边的节点
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
	//二叉树的建构
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



	
	//线索化二叉树





	markThreadOrderly(a, inOrder);
	printf("\n");
	printThreadedTreeOrderly(a, inOrder);


	return 0;
}
