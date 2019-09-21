/*************************************************************************
	> File Name: bf-1.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sat Sep 21 14:23:34 2019
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

	while( i < n && j < m ){
		if(T[i]==P[j]){
			i++;j++;
		}
		else{
			j = 0;
			i += -j+1; //主串复位+1
		}
	}
	return i-j;
}

int main(void){
	char* T = "abdef";
	char* P = "def";

	//cout<<T<<endl;
	int index = match(P, T);
	cout<<"index"<<index<<endl;
}
