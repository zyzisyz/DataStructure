/*************************************************************************
	> File Name: my_bf.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Mon Sep 23 10:25:15 2019
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;


int match(char* P, char* T){
	size_t n = strlen(T), i = 0;
	size_t m = strlen(P), j = 0;

	cout<<"P: "<<P<<endl;
	cout<<"T: "<<T<<endl;

	while( j<m && i<n ){
		if( P[j] == T[i]){
			i++;j++;
		}else{
			i += 1-j;
			j = 0;
		}
	}
	return i - j;
}

int main(void){
	char* P = "aaa";
	char* T = "eeeeeeeaaabbaaeeee";

	cout<<"T: "<<T<<endl;
	cout<<"P: "<<P<<endl;

	cout<<match(P, T)<<endl;

}
