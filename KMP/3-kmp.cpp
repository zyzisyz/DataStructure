/*************************************************************************
	> File Name: 3-kmp.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sat Sep 21 15:00:22 2019
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int* build_next(char* P){
	size_t m = strlen(P), j = 0;
	int* next = new int[m];
	int t = next[0] = -1;
	while(j < m-1)
		if( 0 > t || P[j] == P[t]){
			j++;t++;
			next[j] = t;
		}else
			t = next[t];

	for(int l=0; l<m; l++){
		cout<<next[l]<<" ";
	}
	cout<<endl;

	return next;
}


int match(char* P, char* T){
	size_t n = strlen(T), i = 0;
	cout<<"Text length is "<<n<<endl;

	size_t m = strlen(P), j = 0;
	cout<<"Partten length is "<<m<<endl;

	int* next = build_next(P);

	while(i < n && j < m){
		if( 0>j || T[i] == P[j]){ //0>j是哨兵
			i++;j++;
		}
		else
			j = next[j]; //文本串不用退回
	}

	delete next;

	return i-j;
}


int main(void){
	char* T = "aaaaaeeaeeaaaeeaaeeeeeeeaaaaaaaaaaaaaaabdef";
	char* P = "eeeee";

	//cout<<T<<endl;
	int index = match(P, T);
	cout<<"index num is: "<<index<<endl;
}
