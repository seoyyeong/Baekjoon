#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int cmp(P& a, P& b)
{

	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(void)
{
	vector<P> v;

	int n;
	P prev;
	int cnt = 1;

	scanf("%d", &n);

	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), cmp);

	prev = v[0];

	for (int i = 1; i < n; i++)
	{
		if (prev.second <= v[i].first)
		{
			cnt++;
			prev = v[i];
		}
	}

	printf("%d", cnt);

	return 0;
}
