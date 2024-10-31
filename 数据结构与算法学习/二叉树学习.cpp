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
	int height; // ����
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
	printf("%d->", root->ele);
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
		a->height = 1;
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
///csdn����
void Visit(Node root)
{
	printf("%c->", root->ele);
}
Node First(Node p) 
{
	while (p->leftFlag == false)
	{
		p = p->left;	//�൱���ҵ����������µĽ��
	}
	return p;
}
Node Next(Node p) {
	if (p->rightFlag == 0) {
		return First(p->right);
	}
	return p->right;		//rtag=1��ֱ�ӷ��غ������rchild,��Ϊ��������rchild���������ˣ�ָ���̽��
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

Node leftRotation(Node root) {  //����������ʵ���Ͼ��ǰ���߽��������
	int i = 0;
	Node newRoot = root->right;   //�ȵõ���߽��
	root->right = newRoot->left;   //����߽�������������ԭ���������ұ�ȥ
	newRoot->left = root;   //�����µĸ������߾���ԭ���ĸ������

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



//�ó�����bug:���²���ڵ�ʹ����ƽ�⣬��ת�������ڵ㷢�����ģ��Է��ص��Ǿɸ��ڵ�
Node insert(Node root, E ele) {
	if (root == NULL) {    //������ΪNULL��˵���ҵ��˲���λ�ã�ֱ�Ӵ����µľ�����
		root = createNode(ele);
	}
	else if (root->ele > ele) {   //�Ͷ���������һ�����жϴ�С�������ı����ıߣ�ֱ���ҵ���Ӧ����λ��
		root->left = insert(root->left, ele);
		if (getHeight(root->left) - getHeight(root->right) > 1) {   //�������֮����Ҫ����ƽ�����ӣ������Ƿ�ʧ��
			if (root->left->ele > ele) //������Ҫ�ж�һ���ǲ���������������߻����ұߣ����������Ǳ�˵����LL��������ұ���˵����LR
				root = rightRotation(root);   //LL�͵õ�����֮��Ľ�����õ��µĸ����
			else
				root = leftRightRotation(root);    //LR�͵õ�������������֮��Ľ�����õ��µĸ����
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
	//ǰ��Ĳ������֮��ǵø���һ�����߶�
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return root;  //��󷵻�root����һ��
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
