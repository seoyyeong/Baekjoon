#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

vector<int> v;
int sum;
int n;
int m;

int Search();

int main(void)
{
	int temp;
	int ret;
	int max = 0;

	scanf("%d %d", &n, &m);
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		sum += v[i];
		if (max < v[i])
			max = v[i];
	}
	
	ret = Search();
	if (max > ret)
		ret = max;

	printf("%d", ret);

	return 0;
}

int Search()
{
	int left;
	int mid;
	int right;
	int ret = 0;

	left = v.back();
	right = sum;

	while (right >= left)
	{
		mid = (left + right) / 2;

		int cnt = 0;
		int time = 0;

		for (int i = 0; i < n; i++)
		{

			if (time + v[i] > mid)
			{
				cnt++;
				time = 0;
			}

			time += v[i];
		}

		if (time > 0)
			cnt++;

		if (cnt > m)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return left;
}