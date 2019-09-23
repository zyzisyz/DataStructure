#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

#define MAX 500001
#define MOD 1000000007
#define INF 0x7fffffff

int n, m;
int a[MAX];		// time for each article

int InDegree[MAX];		// indegree of each article
int OutDegree[MAX];		// outdegree of each article

vector<int> prec[MAX];	// precursors of article
vector<int> succ[MAX];	// succeeding articles

int f[MAX];		// earliest time
int g[MAX];		// latest time

int finish_time;


void TopoSort() {
	queue<int> que;
	for (int i = 1; i <= n; i++) { 
		if (!InDegree[i]) que.push(i);
	}
	while (!que.empty()) {
		int tmp_u = que.front();
		que.pop();
		for (int i = 0; i < succ[tmp_u].size(); i++) {
			int tmp_v = succ[tmp_u][i];
			// update f[tmp_v]
			f[tmp_v] = (f[tmp_u] + a[tmp_u]) > f[tmp_v] ? 
						(f[tmp_u] + a[tmp_u]) : f[tmp_v];
			if(--InDegree[tmp_v] == 0) que.push(tmp_v);
		}
		finish_time = f[tmp_u] + a[tmp_u];
	}

	// reversed TopoSort
	for (int i = 1; i <= n; i++) {
		g[i] = finish_time - a[i];
		if (!OutDegree[i]) que.push(i);
	}

	while (!que.empty()) {
		int tmp_v = que.front();
		que.pop();
		for (int i = 0; i < prec[tmp_v].size(); i++) {
			int tmp_u = prec[tmp_v][i];
			// update g[tmp_u]
			g[tmp_u] = (g[tmp_v] - a[tmp_u]) < g[tmp_u] ?
						(g[tmp_v] - a[tmp_u]) : g[tmp_u];
			if (--OutDegree[tmp_u] == 0) que.push(tmp_u);
		}
	}
}

long long Answer() {
	long long answer = g[1] - f[1] + 10;
	for (int i = 2; i <= n; i++) {
		answer *= g[i] - f[i] + 10;
		answer %= MOD;
	}
	return answer % MOD;
}

int main() {

	// input and initialize
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		OutDegree[u]++;
		InDegree[v]++;
		succ[u].push_back(v);
		prec[v].push_back(u);
	}
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	finish_time = 0;

	// output
	TopoSort();
	cout << finish_time << endl;
	cout << Answer() << endl;

	return 0;
}