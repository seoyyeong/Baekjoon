#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
vector<int> truth;
int check[51];

void Union(int a, int b);
int  Find(int a);


int main(void)
{
	int n;
	int m;
	int t;
	int cnt = 0;

	scanf("%d %d", &n, &m);

	v.resize(m);

	scanf("%d", &t);
	truth.resize(t + 1);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &truth[i]);
	}

	for (int i = 0; i <= n; i++)
	{
		check[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int size;
		scanf("%d", &size);
		for (int j = 0; j < size; j++)
		{
			int temp;
			scanf("%d", &temp);
			v[i].push_back(temp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int p = v[i][0];
		for (int j = 1; j < v[i].size(); j++)
		{
			Union(p, v[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool flag = true;
		int cur = v[i][0];
		for (int j = 0; j < t; j++)
		{
			if (Find(cur) == Find(truth[j]))
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			cnt++;
	}

	printf("%d", cnt);
	return 0;
}


void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		check[b] = a;
	}
}

int Find(int a)
{
	if (a == check[a])
	{
		return a;
	}
	else
	{
		return check[a] = Find(check[a]);
	}
}