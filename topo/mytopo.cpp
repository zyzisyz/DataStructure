/*************************************************************************
	> File Name: mytopo.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun Sep 22 20:42:35 2019
 ************************************************************************/

#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

int n,e;
vector<list<int>> Adj;
vector<int> inDegree;
vector<int> path;

stack<int> s;

void init_grap(){
	cout<<"input some thing"<<endl;
	cin>>n>>e;	

	Adj.assign(n, list<int>());
	inDegree.assign(n, 0);
	path.reserve(n);

	int v1,v2;
	for(int i=0; i<e; i++){
		cin>>v1>>v2;
		Adj[v1].push_back(v2);
		inDegree[v2]+=1;
	}
	cout<<"indegree check: ";
	for(auto item: inDegree)
		cout<<item<<" ";
	cout<<endl;
}

void topo_sort(){
	for(int i=0; i<n; i++){
		if(inDegree[i]==0)
			s.push(i);
	}

	int temp;
	while(!s.empty()){
		temp = s.top();
		s.pop();
		for(auto it=Adj[temp].begin();it!=Adj[temp].end();it++){
			inDegree[*it]-=1;
			if(inDegree[*it]==0) s.push(*it);
		}
		path.push_back(temp);
	}
	
	//cout<<"size of path: "<<path.size()<<endl;
	//cout<<"capacity of path: "<<path.capacity()<<endl;

	for(auto item: path){
		cout<<item<<" ";
	}
}


int main(void){
	init_grap();
	topo_sort();
}
