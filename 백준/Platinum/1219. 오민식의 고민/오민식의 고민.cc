#include <iostream>
#include <vector>
#include <tuple>

#define MIN -9'223'372'036'854'775'808
#define MAX 9'223'372'036'854'775'807
using namespace std;
typedef tuple<long long, long long, long long> T;

vector<T> v;
vector<long long> cost;
vector<long long> maxCost;


int main()
{

	int n;
	int s;
	int e;
	int m;
	scanf("%d %d %d %d", &n, &s, &e, &m);

	cost.resize(n);
	maxCost.resize(n);

	fill(cost.begin(), cost.end(), (long long)MIN);

	for (int i = 0; i < m; i++)
	{
		int a;
		int b;
		int c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ a, b, c });
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &maxCost[i]);
	}

	cost[s] = maxCost[s];

	for (int i = 0; i <= n + 50; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int start = get<0>(v[j]);
			int end = get<1>(v[j]);
			long long c = get<2>(v[j]);

			if (cost[start] == MIN)
			{
				continue;
			}
			else if (cost[start] == MAX)
			{
				cost[end] = MAX;
			}
			else if (cost[end] < cost[start] + maxCost[end] - c)
			{
				cost[end] = cost[start] + maxCost[end] - c;

				if (i >= n - 1)
				{
					cost[end] = MAX;
				}
			}
		}
	}

	if (cost[e] == MIN)
	{
		printf("gg");
	}
	else if (cost[e] == MAX)
	{
		printf("Gee");
	}
	else
	{
		printf("%lld", cost[e]);
	}

	return 0;
}
