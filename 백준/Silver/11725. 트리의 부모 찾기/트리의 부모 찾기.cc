#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> v;
vector<int> parent;
queue<int> q;

int main(void)
{
	int n;
	scanf("%d", &n);
	v.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	parent[1] = -1;
	q.push(1);

	while (q.size() > 0)
	{
		int temp = q.front();
		q.pop();

		for (int i = 0; i < v[temp].size(); i++)
		{
			if (parent[temp] != 0)
			{
				if (parent[v[temp][i]] == 0)
				{
					q.push(v[temp][i]);
					parent[v[temp][i]] = temp;
				}

			}
		}

	}

	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", parent[i]);
	}

	return 0;
}