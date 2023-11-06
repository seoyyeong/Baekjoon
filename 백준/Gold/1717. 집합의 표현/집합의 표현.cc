#include <iostream>
#include <vector>

int arr[1'000'001];

void Union(int a, int b);
int Find(int a);


int main(void)
{
	int n;
	int m;
	int t;
	int a;
	int b;

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &t, &a, &b);
		if (t == 0)
		{
			Union(a, b);
		}
		else
		{
			a = Find(a);
			b = Find(b);
			if (a == b)
				printf("YES\n");
			else
				printf("NO\n");
		}

	}

	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		arr[b] = a;
	}

}

int Find(int a)
{
	if (a == arr[a])
		return a;
	else
		return arr[a] = Find(arr[a]);
}