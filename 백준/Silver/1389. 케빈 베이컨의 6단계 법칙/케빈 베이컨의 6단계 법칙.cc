#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NODE 101
#define INF 100'000

int graph[MAX_NODE][MAX_NODE];

int main(void)
{
	int n;
	int m;
	int cnt = INF;
	int ret;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (s != e)
				{
					graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
					graph[e][s] = graph[s][e];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] != INF)
				temp += graph[i][j];
		}
		if (cnt > temp)
		{
			cnt = temp;
			ret = i;
		}
	}

	printf("%d", ret);

	return 0;
}