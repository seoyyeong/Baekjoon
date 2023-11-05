
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
queue<int> q;
vector<int> ans;
vector<int> visited;
int n;
int m;
int k;
int x;
int cnt;

void BFS(void);

int main(void)
{
	int temp1;
	int temp2;

	scanf("%d %d %d %d", &n, &m, &k, &x);

	if (k == 0)
	{
		printf("%d", x);
		return 0;
	}

	graph.resize(n + 1);
	visited.resize(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		graph[temp1].push_back(temp2);
	}

	BFS();

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == k)
			ans.push_back(i);
	}

	if (ans.size() == 0)
	{
		printf("-1");
		return 0;
	}

	vector<int>::iterator iter;
	for (iter = ans.begin(); iter != ans.end(); ++iter)
	{
		printf("%d\n", *iter);
	}

	return 0;
}

void BFS(void)
{
	q.push(x);
	visited[x]++;

	while (q.size() > 0)
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (visited[graph[cur][i]] == -1)
			{
				visited[graph[cur][i]] = visited[cur] + 1;
				q.push(graph[cur][i]);
			}
		}
	}

}