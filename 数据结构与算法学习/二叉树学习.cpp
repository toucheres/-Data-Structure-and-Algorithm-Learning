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
	int height; // 树高
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
	printf("%d->", root->ele);
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
		a->height = 1;
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

Node createNode(E tele)
{
	Node a = (Node)malloc(sizeof(struct TreeNode));
	if (a)
	{
		a->height = 1;
		a->ele = tele;
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
///csdn方法
void Visit(Node root)
{
	printf("%c->", root->ele);
}
Node First(Node p) 
{
	while (p->leftFlag == false)
	{
		p = p->left;	//相当于找到树的最左下的结点
	}
	return p;
}
Node Next(Node p) {
	if (p->rightFlag == 0) {
		return First(p->right);
	}
	return p->right;		//rtag=1，直接返回后继线索rchild,因为线索化后，rchild就是线索了，指向后继结点
}
void Inorder(Node root) {
	for (Node p = First(root); p != NULL; p = Next(p))
		Visit(p);
}



int max(int a, int b) {
	return a > b ? a : b;
}

int getHeight(Node root) {
	if (root == NULL) return 0;
	return root->height;
}

Node leftRotation(Node root) {  //左旋操作，实际上就是把左边结点拿上来
	int i = 0;
	Node newRoot = root->right;   //先得到左边结点
	root->right = newRoot->left;   //将左边结点的左子树丢到原本根结点的右边去
	newRoot->left = root;   //现在新的根结点左边就是原本的跟结点了

	root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
	newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
	return newRoot;
}

Node rightRotation(Node root) {
	Node newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
	newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
	return newRoot;
}

Node leftRightRotation(Node root) {
	root->left = leftRotation(root->left);
	return rightRotation(root);
}

Node rightLeftRotation(Node root) {
	root->right = rightRotation(root->right);
	return leftRotation(root);
}



//该程序有bug:当新插入节点使树不平衡，旋转后若根节点发生更改，仍返回的是旧根节点
Node insert(Node root, E ele) {
	if (root == NULL) {    //如果结点为NULL，说明找到了插入位置，直接创建新的就完事
		root = createNode(ele);
	}
	else if (root->ele > ele) {   //和二叉搜索树一样，判断大小，该走哪边走哪边，直到找到对应插入位置
		root->left = insert(root->left, ele);
		if (getHeight(root->left) - getHeight(root->right) > 1) {   //插入完成之后，需要计算平衡因子，看看是否失衡
			if (root->left->ele > ele) //接着需要判断一下是插入了左子树的左边还是右边，如果是左边那边说明是LL，如果是右边那说明是LR
				root = rightRotation(root);   //LL型得到左旋之后的结果，得到新的根结点
			else
				root = leftRightRotation(root);    //LR型得到先左旋再右旋之后的结果，得到新的根结点
		}
	}
	else if (root->ele < ele) {
		root->right = insert(root->right, ele);
		if (getHeight(root->left) - getHeight(root->right) < -1) {
			if (root->right->ele < ele)
				root = leftRotation(root);
			else
				root = rightLeftRotation(root);
		}
	}
	//前面的操作完成之后记得更新一下树高度
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return root;  //最后返回root到上一级
}




//
//int main()
//{
//	Node root = creatNodeThread();
//	root->ele = 15;
//	printTree_inOrder(root);
//	printf("\n");
//	printTree_inOrder(insert(root, 12));
//	printf("\n");
//	printTree_inOrder(insert(root, 20));
//	printf("\n");
//	printTree_inOrder(insert(root, 11));
//	printf("\n");
//	printTree_inOrder(insert(root, 13));
//	printf("\n");
//	printTree_inOrder(insert(root, 14));
//	printf("\n");
//	printTree_inOrder(insert(root, 77));
//	printf("\n");
//	printTree_inOrder(insert(root, 45));
//	printf("\n");
//	printTree_inOrder(insert(root, 121));
//	printf("\n");
//	printTree_inOrder(insert(root, 19));
//	printf("\n");
//	printTree_inOrder(insert(root, 1));
//	printf("\n");
//
//	return 0;
//}
