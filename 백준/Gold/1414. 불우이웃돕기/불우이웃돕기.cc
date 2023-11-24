#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> T;
vector<T> v;
vector<int> uf;

void Union(int a, int b);
int Find(int a);

int main(void)
{

	int n;
	int sum = 0;
	scanf("%d", &n);
	uf.resize(n);
	for (int i = 0; i < n; i++)
	{
		uf[i] = i;
	}

	for (int i = 0; i < n; i++)
	{

		getchar();
		for (int j = 0; j < n; j++)
		{
			char c;
			scanf("%c", &c);
			if (c == '0')
			{
				continue;
			}
			if (c <= 'z' && c >= 'a')
			{
				c -= 'a' - 1;
			}
			else
			{
				c -= 'A' - 27;
			}
			sum += c;
			if (i != j)
			{
				v.push_back({ c,i,j });
			}
		}
	}

	sort(v.begin(), v.end());

	int ret = 0;
	int edge = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int weight = get<0>(v[i]);
		int start = get<1>(v[i]);
		int end = get<2>(v[i]);

		if (Find(start) != Find(end))
		{
			Union(start, end);
			ret += weight;
			edge++;
		}
	}

	if (edge == n - 1)
	{
		printf("%d", sum - ret);
	}
	else
	{
		printf("-1");
	}

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