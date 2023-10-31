#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v;
	int n;
	int sum = 0;

	scanf("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	int idx = 0;

	while (1)
	{
		if (idx >= n - 1)
		{
			if (idx == n - 1)
			{
				sum += v[idx];
			}
			printf("%d", sum);
			return 0;
		}

		if (v[idx] <= 0 && v[idx + 1] <= 0)
		{
			sum += v[idx] * v[idx + 1];
			idx += 2;
		}
		else if (v[idx] <= 0)
		{
			sum += v[idx];
			v[idx] = 0;
			break;
		}
		else
			break;
	}

	idx = n - 1;

	while (1)
	{
		if (idx < 1 || v[idx] < 0)
			break;

		if (v[idx - 1] > 1 && v[idx] > 1)
		{
			sum += v[idx] * v[idx - 1];
			idx -= 2;
		}

		else if (v[idx - 1] == 1)
		{
			sum += v[idx] + v[idx - 1];
			idx -= 2;
		}

		else if (v[idx - 1] == 0)
		{
			sum += v[idx];
			break;
		}

		else
		{
			sum += v[idx];
			break;
		}
			

	}

	if (idx == 0)
		sum += v[idx];

	printf("%d", sum);

	return 0;
}