#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(void)
{

	int n;
	int m;
	scanf("%d %d", &n, &m);

	int size = 2;
	while (size < n)
	{
		size *= 2;
	}

	v.resize(size * 2);

	for (int i = size; i < size + n; i++)
	{
		scanf("%d", &v[i]);
	}

	for (int i = size; i < size + n; i += 2)
	{
		int idx = i / 2;
		while (1)
		{
			v[idx] = min(v[idx * 2], v[idx * 2 + 1]);
			idx /= 2;
			if (idx == 0)
			{
				break;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		int b;
		int ans = 1'000'000'000;
		scanf("%d %d", &a, &b);

		a += size - 1;
		b += size - 1;
		while (a <= b)
		{
			if (a % 2 == 1)
			{
				ans = min(v[a], ans);
				a++;
			}
			if (b % 2 == 0)
			{
				ans = min(v[b], ans);
				b--;
			}
			a /= 2;
			b /= 2;
		}

		printf("%d\n", ans);
	}


	return 0;
}