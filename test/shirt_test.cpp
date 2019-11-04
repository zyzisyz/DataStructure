/*************************************************************************
	> File Name: shirt_test.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun Nov  3 23:24:03 2019
 ************************************************************************/

#include<iostream>
#include<random>

using namespace std;

int main(void){
	bool equal = true;
	default_random_engine e;


	for(int i=0;i<111110;i++){
		int test = -i;

		int temp = test>>1;
		temp = temp<<1;

		if(test!=temp){
			cout<<"test: "<<test<<endl;
			cout<<"temp: "<<temp<<endl;

			equal = false;
			break;
		}
	}

	cout<<equal<<endl;

}

