using namespace std;
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
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

// 其他需要的库

//节点的定义
typedef struct TreeNode
{
	E ele;
	struct TreeNode* left;
	struct TreeNode* right;
}* Node;

//前序遍历打印Tree(递归)
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

 
int main()
{
	//二叉树的建构
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
	d->left = NULL;//防止野指针
	d->right = NULL;
	e->left = NULL;
	e->right = NULL;	
	c->left = NULL;
	c->right = NULL;


	printTree_inOrder(a);
	printf("\n");
	printTree_tpOrder(a);


}