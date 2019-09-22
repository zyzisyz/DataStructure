#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;
 
vector<list<int>> Adj; 
vector<int> inDegree; 
stack<int> stk; //保存当前入度为0的节点编号

void CreatGraph()
{
	int n, m, v1, v2;//n nodes; m edge
	cout<<"input some thing"<<endl;
	cin >> n >> m;

	Adj.assign(n, list<int>());

	inDegree.assign(n, 0);
	while (m--)
	{
		cin >> v1 >> v2;
		Adj[v1].push_back(v2);
		inDegree[v2]++;
	}

	for (int i = 0; i < n;i++)
		if (inDegree[i] == 0) stk.push(i);
}

void tpSort()
{
	vector<int> vec;
	int v;
	while (!stk.empty())
	{
		v = stk.top();
		stk.pop();
		//inDegree[v] = -1;
		//遍历与节点v相连的节点
		for (auto it = Adj[v].begin(); it != Adj[v].end(); it++)
		{
			inDegree[*it]--;
			if (inDegree[*it] == 0) stk.push(*it);
		}
		//Adj[v].clear(); //本行可以省略，以提升程序效率
		vec.push_back(v);
	}

	/*
	if (vec.size() != inDegree.size())
	{
		cout <<"loop"<<endl;
		return;
	}
	*/

	for (auto item : vec)
		cout << item << " ";
	cout << endl;
}

int main(void)
{
	CreatGraph();
	tpSort();
	return 0;
}
