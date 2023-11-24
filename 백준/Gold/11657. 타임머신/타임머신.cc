#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define MAX 2147483647

using namespace std;

typedef tuple<int, int, long long> T;
vector<T> v;
vector<long long> dist;


int main(void)
{
	int n;
	int m;
	int a;
	int b;
	int c;

	scanf("%d %d", &n, &m);
	dist.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		dist[i] = MAX;
	}
	dist[1] = 0;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(make_tuple(a,b,c));
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			T temp = v[j];
			int s = get<0>(temp);
			int e = get<1>(temp);
			int t = get<2>(temp);

			if (dist[s] != MAX && dist[e] > dist[s] + t)
			{
				dist[e] = dist[s] + t;
			}
		}
	}

	bool flag = false;

	for (int i = 0; i < m; i++)
	{
		T temp = v[i];
		int s = get<0>(temp);
		int e = get<1>(temp);
		int t = get<2>(temp);

		if (dist[s] != MAX && dist[e] > dist[s] + t)
		{
			flag = true;
			break;
		}
	}

	if (flag == true)
	{
		printf("-1");
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] != MAX)
			{
				printf("%lld\n", dist[i]);
			}
			else
			{
				printf("-1\n");
			}
		}

	}

	return 0;
}