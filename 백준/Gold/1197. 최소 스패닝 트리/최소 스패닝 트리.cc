#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> T;
vector<T> list;
vector<int> uf;

void Union(int a, int b);
int Find(int a);

int main(void)
{
	int v;
	int e;
	int ret = 0;

	scanf("%d %d", &v, &e);

	uf.resize(v + 1);
	for (int i = 1; i <= v; i++)
	{
		uf[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		int a;
		int b;
		int c;
		scanf("%d %d %d", &a, &b, &c);
		list.push_back(make_tuple(c, a, b));
	}

	sort(list.begin(), list.end());

	for (int i = 0; i < e; i++)
	{
		int weight = get<0>(list[i]);
		int start = get<1>(list[i]);
		int end = get<2>(list[i]);

		if (Find(start) != Find(end))
		{
			Union(start, end);
			ret += weight;
		}
	}

	printf("%d", ret);

	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		uf[b] = a;
	}
}

int Find(int a)
{
	if (a == uf[a])
	{
		return a;
	}

	return uf[a] = Find(uf[a]);
}