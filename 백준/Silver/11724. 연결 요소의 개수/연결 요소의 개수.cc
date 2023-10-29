#include <iostream>
#include <vector>
#include <list>
#include <stack>
#define MAX_SIZE 1001

bool graph[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE];
bool check[MAX_SIZE];


void DFS(int node, bool graph[][MAX_SIZE], bool* visit, bool* check);

int main(void)
{
	int n;
	int m;
	int u;
	int v;
	int cnt;
	int checkcnt = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u][v] = true;
		graph[v][u] = true;
		check[u] = true;
		check[v] = true;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (check[i] == true)
			checkcnt++;
	}

	cnt = n - checkcnt;

	for (int i = 1; i < MAX_SIZE; i++)
	{
		if (check[i] == true && visit[i] == false)
		{
			DFS(i, graph, visit, check);
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}


void DFS(int node, bool graph[][MAX_SIZE], bool* visit, bool* check)
{
	if (visit[node] == true)
		return;

	visit[node] = true;

	for (int i = 1; i < MAX_SIZE; i++)
	{
		if (graph[node][i] == true && visit[i] == false)
		{
			DFS(i, graph, visit, check);
		}
	}
}