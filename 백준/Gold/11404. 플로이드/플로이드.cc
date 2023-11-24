#include <iostream>
#include <vector>

#define MAX_NODE 101
#define INF 100'000'000
using namespace std;


int dist[MAX_NODE][MAX_NODE];

//D[S][E]=min(D[S]{e}, D[S][K]+d[K][E]

int main(void)
{
	int n;
	int m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < MAX_NODE; i++)
	{
		for (int j = 0; j < MAX_NODE; j++)
		{
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		int b;
		int c;
		scanf("%d %d %d", &a, &b, &c);

		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (s == e)
					continue;
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", dist[i][j]);
			}
		}
		printf("\n");
	}

}