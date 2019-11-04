/*************************************************************************
	> File Name: test.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Mon Nov  4 17:40:38 2019
 ************************************************************************/

#include<iostream>
#include<random>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
	default_random_engine e;
	vector<int> num;
	for(int i=0; i<100; i++){
		num.push_back(int(e()%100));
	}
	sort(num.begin(), num.end());
	for(auto item: num){
		cout<<item<<endl;
	}
	cout<<endl;
}
