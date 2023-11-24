#include <iostream>
#include <algorithm>
#define MAX_NODE 100

int graph[MAX_NODE][MAX_NODE];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				if (graph[s][k] == 1 && graph[k][e] == 1)
				{
					graph[s][e] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}


	return 0;
}