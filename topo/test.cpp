/*************************************************************************
	> File Name: test.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun Sep 22 19:28:30 2019
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int main(void)
{
	vector<int> a;
	cout<<a.size()<<endl;

	a.assign(5, 0);
	//a.resize(5);
	cout<<a.size()<<endl;
	for(int i=0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(auto item: a)
		cout<<item<<" ";
	cout<<endl;
}


