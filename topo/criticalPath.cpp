/*************************************************************************
	> File Name: criticalPath.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun Sep 22 19:16:32 2019
 ************************************************************************/

#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

vector<list<int>> Adj; //adj
int n, e;

vector<int> inDegree;
vector<int> f, g;
vector<int> path;

stack<int> s;

int init_graph()
{
	cout << "input something\n";
	cin >> n >> e;

	Adj.assign(n, list<int>());
	f.reserve(n);
	g.reserve(n);
	path.reserve(n);
	inDegree.assign(n, 0);

	int v1, v2;
	for (int i = e; i < e; i++)
	{
		cin >> v1 >> v2;
		Adj[v1].push_back(v2);
		inDegree[v2]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (inDegree[i] == 0)
		{
			s.push(i);
		}
	}
}

void topo_sort()
{
	int top;
	while (!s.empty())
	{
		top = s.top();
		s.pop();
		for (auto it = Adj[top].begin(); it != Adj[top].end(); it++)
		{
			inDegree[*it]--;
			if (inDegree[*it] == 0)
			{
				s.push(*it);
			}
		}
		path.push_back(top);
	}
	for (auto item : path)
	{
		cout << item << " ";
	}
	cout<<endl;
}

int main(void)
{
	init_graph();
	topo_sort();
}