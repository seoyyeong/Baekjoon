#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

vector<vector<int>> graph;
bool visited[2001];
int n;
bool check;

void DFS(int idx, int depth);

int main(void)
{
	int m;
	int a;
	int b;

	scanf("%d %d", &n, &m);

	graph.resize(n);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		(DFS(i, 1));

		if (check == true)
		{
			printf("1");
			return 0;
		}
	}

	printf("0");

	return 0;
}

void DFS(int idx, int depth)
{
	if (depth >= 5 || check == true)
	{
		check = true;
		return;
	}


	visited[idx] = true;

	for (int i : graph[idx])
	{
		if (visited[i] == false)
		{
			DFS(i, depth + 1);
		}
	}

	visited[idx] = false;
}