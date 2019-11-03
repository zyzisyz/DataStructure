/*************************************************************************
  > File Name: kmp_improved.cpp
  > Author: Yang Zhang 
  > Mail: zyziszy@foxmail.com 
  > Created Time: Sun Nov  3 23:11:00 2019
 ************************************************************************/
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int* buildNext ( char* P ) { 
	size_t m = strlen ( P ), j = 0;
	int* N = new int[m]; 
	int t = N[0] = -1; 
	while ( j < m - 1 )
		if ( 0 > t || P[j] == P[t] ) {
			N[j] = ( P[++j] != P[++t] ? t : N[t] );
		} else //ʧ??
			t = N[t];
	return N;
}

int main(void){
	char* P ="OIOO";
	int* n = buildNext(P);
	for(int i=0; i<4; i++){
		cout<<P[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<4; i++){
		cout<<n[i]<<" ";
	}
	cout<<endl;
}



