#include <iostream>
#include <vector>

using namespace std;

int arr[201][201];
int UnionArr[201];
int City[1001];

void Union(int a, int b);
int Find(int a);

int main(void)
{
	int n;
	int m;
	int f;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		UnionArr[i] = i;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &City[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1)
			{
				Union(i, j);
			}
		}
	}

	f = Find(City[1]);

	for (int i = 2; i <= m; i++)
	{
		if (f != Find(City[i]))
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		UnionArr[b] = a;
	}

}

int Find(int a)
{
	if (a == UnionArr[a])
		return a;

	return UnionArr[a] = Find(UnionArr[a]);
}