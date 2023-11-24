#include <iostream>
#include <vector>

using namespace std;
vector<long long> v;

int main(void)
{

	long long n;
	long long m;
	long long k;

	scanf("%lld %lld %lld", &n, &m, &k);

	long long size = 2;
	while (size < n)
	{
		size *= 2;
	}
	v.resize(size * 2);

	for (long long i = size; i < size + n; i++)
	{
		scanf("%lld", &v[i]);
	}

	for (long long i = size; i < size + n; i+=2)
	{
		long long idx = i / 2;
		while (1)
		{
			v[idx] = v[idx * 2] + v[idx * 2 + 1];

			idx /= 2;
			if (idx == 0)
			{
				break;

			}
		}
	}

	for (long long i = 0; i < m + k; i++)
	{
		long long a;
		long long b;
		long long c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
		{
			v[size + b - 1] = c;
			int idx = (size + b - 1)/2;

			while (1)
			{
				v[idx] = v[idx * 2] + v[idx * 2 + 1];

				idx /= 2;

				if (idx == 0)
				{
					break;

				}
			}
		}
		else if (a == 2)
		{

			b = size + b - 1;
			c = size + c - 1;
			long long sum = 0;

			while (c >= b)
			{
				if (b % 2 == 1)
				{
					sum = sum += v[b];
					b++;
				}
				if (c % 2 == 0)
				{
					sum = sum + v[c];
					c--;
				}
				b /= 2;
				c /= 2;
			}

			printf("%lld\n", sum);
		}

	}

	return 0;
}