/*************************************************************************
	> File Name: criticalPath.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun Sep 22 19:16:32 2019
 ************************************************************************/

#include<iostream>
#include<stack>
#include<list>
#include<vector>

using namespace std;


int num_nodes, num_edge;

vector<int> f; //ealiest
vector<int> g; //latest

vector<list<int>> Adj; //graph adj

vector<int> weight; //time

vector<int> inDegree;

stack<int> s;

vector<int> path;

void init_grap(void){
	cout<<"input"<<endl;
	//input
	cin>>num_nodes>>num_edge;

	f.resize(num_nodes);
	g.resize(num_nodes);

	weight.resize(num_nodes);
	inDegree.resize(num_nodes);

	Adj.assign(num_nodes, list<int>());

	int temp;
	for(int i=0; i<num_nodes; i++){
		cin>>temp;
		weight[i] = temp;
	}

	int v1=0;
	int v2=0;
	for(int i=0; i<num_edge; i++){	
		cin >> v1 >> v2;
		Adj[v1].push_back(v2);
		inDegree[v2]++;
	}
}

void topo_sort(){
	for(int i=0;i<num_nodes;i++){
		if(inDegree[i]==0)	
			s.push(i);
	}

	int top;
	while (!s.empty())
	{
		top = s.top();
		s.pop();

		for (auto it = Adj[top].begin(); it != Adj[top].end(); it++)
		{
			inDegree[*it]--;
			if (inDegree[*it] == 0) 
				s.push(*it);
		}
		path.push_back(top);
	}

	for(auto item: path){
		cout<<item<<" ";
	}
	cout<<endl;

}


void CriticalPath(void){

}


int main(void){
	init_grap();
	topo_sort();
}
