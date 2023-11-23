#include <iostream>
#include <vector>
#include <queue>

#define MAX 10'000'000
using namespace std;

typedef pair<int, int> P;
vector<vector<P>> Node;
vector<int> dist;
priority_queue<P, vector<P>, greater<P>> q;

int main(void)
{
	int v;
	int e;
	int k;

	scanf("%d %d %d", &v, &e, &k);
	Node.resize(v + 1);
	dist.resize(v + 1);

	for (int i = 1; i <= v; i++)
	{
		dist[i] = MAX + 1;
	}
	dist[k] = 0;

	for (int i = 0; i < e; i++)
	{
		int u;
		P p;
		scanf("%d %d %d", &u, &p.second, &p.first);
		Node[u].push_back(p);
	}

	q.push({ 0,k });

	while (q.size() > 0)
	{
		int curIdx = q.top().second;
		int curdist = q.top().first;
		q.pop();
		
		if (dist[curIdx] < curdist)
		{
			continue;
		}

		for (int i = 0; i < Node[curIdx].size(); i++)
		{
			int nextIdx = Node[curIdx][i].second;
			int nextDist = curdist + Node[curIdx][i].first;

			if (dist[nextIdx] > nextDist)
			{
				dist[nextIdx] = nextDist;
				q.push({ nextDist, nextIdx });
			}

		}


	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] <= MAX)
		{
			printf("%d\n", dist[i]);
		}
		else
		{
			printf("INF\n");
		}
	}

	return 0;
}