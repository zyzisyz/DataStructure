/*************************************************************************
	> File Name: bf-2.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sat Sep 21 14:46:24 2019
 ************************************************************************/


#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int match(char* P, char* T){
	size_t n = strlen(T), i = 0;
	cout<<"Text length is "<<n<<endl;

	size_t m = strlen(P), j = 0;
	cout<<"Partten length is "<<m<<endl;

	for(; i<(n-m); i++){
		for(j = 0; j < m; j++){
			if(T[i+j]!=P[j])
				break;
		}
		if(j>=n)
			break;
	}
	return i;
}

int main(void){
	char* T = "abaaaaaaaaaaaaaaaaaaaaaaaaaaadef";
	char* P = "def";

	//cout<<T<<endl;
	int index = match(P, T);
	cout<<"index num is: "<<index<<endl;
}
