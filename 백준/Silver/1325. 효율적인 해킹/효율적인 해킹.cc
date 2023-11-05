#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> graph;
queue<int> q;
vector<int> ans;
vector<bool> visited;
int n;
int m;
int depth;

void BFS(int n);

int main(void)
{
	int temp1;
	int temp2;

	scanf("%d %d", &n, &m);

	graph.resize(n + 1);
	visited.resize(n + 1);
	ans.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		graph[temp1].push_back(temp2);
	}

	for (int i = 1; i <= n; i++)
	{
		visited.assign(visited.size(), 0);
		BFS(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (depth < ans[i])
			depth = ans[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == depth)
			printf("%d ", i);
	}

	return 0;
}

void BFS(int n)
{
	q.push(n);
	visited[n] = true;
	while (q.size() > 0)
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (visited[graph[cur][i]] == false)
			{
				visited[graph[cur][i]] = true;
				ans[graph[cur][i]]++;
				q.push(graph[cur][i]);
			}
		}

	}
}