#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> parent;
vector<int> depth;
vector<bool> visited;

void DFS(int a, int d);

int main(void)
{
	int n;
	scanf("%d", &n);

	int temp = n;
	int size = 0;
	while (temp > 0)
	{
		temp /= 2;
		size++;
	}
	v.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 0; i <= size + 1; i++)
	{
		parent[i].resize(n + 1);
	}
	depth.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1, 0);

	for (int j = 1; j <= size; j++)
	{
		for (int k = 1; k <= n; k++)
		{
			parent[j][k] = parent[j - 1][parent[j - 1][k]];
		}
	}
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);


		if (depth[a] < depth[b])
		{
			for (int j = size; j >= 0; j--)
			{
				if (pow(2, j) <= depth[b] - depth[a])
				{
					if (depth[a] <= depth[parent[j][b]])
					{
						b = parent[j][b];
					}
				}
			}
		}
		else
		{
			for (int j = size; j >= 0; j--)
			{
				if (pow(2, j) <= depth[a] - depth[b])
				{
					if (depth[b] <= depth[parent[j][a]])
					{
						a = parent[j][a];
					}
				}
			}
		}
		
		int j;
		for (j = size; j >= 0 && a != b; j--)
		{
			if (parent[j][a] != parent[j][b])
			{
				a = parent[j][a];
				b = parent[j][b];
			}
		}

		if (a != b)
			a = parent[0][a];

		printf("%d\n", a);
	}

	return 0;
}

void DFS(int a, int d)
{
	if (visited[a])
		return;

	visited[a] = true;
	depth[a] = d;
	for (int i = 0; i < v[a].size(); i++)
	{
		if (parent[0][a] != v[a][i])
			parent[0][v[a][i]] = a;
		DFS(v[a][i], d + 1);
	}

}