#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> parent;
vector<int> depth;
vector<bool> visited;

void DFS(int a, int d);

int main(void)
{
	int n;
	scanf("%d", &n);

	v.resize(n + 1);
	parent.resize(n + 1);
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

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);

		while (depth[a] != depth[b])
		{
			if (depth[a] < depth[b])
			{
				b = parent[b];
			}
			else
			{
				a = parent[a];
			}
		}

		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}
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
		if (parent[a] != v[a][i])
			parent[v[a][i]] = a;
		DFS(v[a][i], d + 1);
	}

}