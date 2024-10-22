#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace  std;


void printvector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printvector(vector<char> v)
{
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//int main()
//{
//	vector<int>i1={0,1,2,3,4,5,6};
//	for (auto &q : i1)
//	{
//		cout << q <<endl;
//	} 
//}