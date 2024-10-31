#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stdio.h>
#include<limits.h>
#include<cmath>
#define T int


class myvipqeu
{
public:
	T* arr;
	int cap;
	int size;

	void push(T tpnum);
	void pop();
	void print();
	

	myvipqeu(int size = 0);
	~myvipqeu();
	T operator[](int index);

protected:
	int getHight();
	int getLeftChildIndex(int par);
	int getRightChildIndex(int par);

};