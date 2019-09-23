/*************************************************************************
	> File Name: topo_sort.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Mon Sep 23 09:48:34 2019
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<list>

using namespace std;

vector<list<int>> Adj;
int n,e;

vector<int> inDegree;
vector<int> path;

stack<int> s;

void init_graph(){
	cout<<"input some thing\n";
	
	cin>>n>>e;

	Adj.assign(n, list<int>());
	inDegree.assign(n, 0);
	path.reserve(n);


	int v1, v2;
	for(int i=0; i<e; i++){
		cin>>v1>>v2;
		inDegree[v2]++;
		Adj[v1].push_back(v2);
	}

	for(int i=0; i<n; i++){
		if(inDegree[i]==0){
			s.push(i);
		}
	}

}


void topo_sort(){
	int top;
	while(!s.empty()){
		top = s.top();
		s.pop();
		for(auto it = Adj[top].begin();it != Adj[top].end(); it++){
			inDegree[*it]--;
			if(inDegree[*it]==0) {s.push(*it);}
		}
		path.push_back(top);
	}

	for (auto item : path) {cout<<item<<" ";}
	cout<<endl;
}


int main(void){
	init_graph();
	topo_sort();
}
