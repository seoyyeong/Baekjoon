#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> order;
vector<int> timev;
vector<int> result;
queue<int> q;

int main(void)
{

	int n;
	scanf("%d", &n);
	v.resize(n + 1);
	order.resize(n + 1);
	timev.resize(n + 1);
	result.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int level = 0;
		int temp;
		scanf("%d", &timev[i]);
		while (1)
		{
			scanf("%d", &temp);
			if (temp == -1)
			{
				break;
			}
			v[temp].push_back(i);
			order[i]++;
		}
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
		int front = q.front();
		q.pop();

		for (int i = 0; i < v[front].size(); i++)
		{
			result[v[front][i]] = max(result[v[front][i]], result[front]+timev[front]);
			order[v[front][i]]--;
			if (order[v[front][i]] == 0)
			{
				q.push(v[front][i]);
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", timev[i] + result[i]);
	}

}