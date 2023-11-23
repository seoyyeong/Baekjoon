#include <iostream>
#include <vector>
#include <queue>

#define MAX 100'000'001
using namespace std;

typedef pair<int, int> P;
vector<vector<P>> v;
vector<int> cost;
priority_queue<P, vector<P>, greater<P>> pq;

int main(void)
{
	int n;
	int m;
	int s;
	int e;

	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	cost.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		cost[i] = MAX;
	}

	for (int i = 0; i < m; i++)
	{
		int ts;
		int te;
		int c;
		scanf("%d %d %d", &ts, &te, &c);
		v[ts].push_back({ c,te });
	}

	scanf("%d %d", &s, &e);
	cost[s] = 0;
	pq.push({ 0,s });

	while (pq.size() > 0)
	{
		int curIdx = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (cost[curIdx] < curCost)
		{
			continue;
		}

		for (int i = 0; i < v[curIdx].size(); i++)
		{
			int nextIdx = v[curIdx][i].second;
			int nextCost = v[curIdx][i].first + curCost;

			if (cost[nextIdx] > nextCost)
			{
				cost[nextIdx] = nextCost;
				pq.push({ nextCost, nextIdx });
			}

		}

	}


	printf("%d", cost[e]);

	return 0;
}