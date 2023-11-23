#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> order;
queue<int> q;
int n;
int m;


int main(void)
{

	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	order.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		order[b]++; 
	}

	for (int i = 1; i <= n; i++)
	{
		if (order[i] == 0)
		{
			q.push(i);
		}
	}

	while (q.size() > 0)
	{
		int  i = q.front();
		q.pop();
		printf("%d ", i);

		for (int j = 0; j < v[i].size(); j++)
		{
			order[v[i][j]]--;

			if (order[v[i][j]] == 0)
			{
				q.push(v[i][j]);
			}
		}
	}

	return 0;
}