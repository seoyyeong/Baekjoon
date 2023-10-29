#include <iostream>
#include <cmath>

bool isPrime(int n);
void FindPrime(int n, int cnt);


int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 2; i < 9; i++)
	{
		FindPrime(i, n);
	}

	return 0;
}

void FindPrime(int n, int cnt)
{
	if (cnt == 1)
	{
		if (isPrime(n) == true)
			printf("%d\n", n);
		return;
	}


	if (isPrime(n) == true)
	{
		for (int i = 1; i < 10; i++)
		{
			FindPrime(n * 10 + i, cnt - 1);
		}
	}
	else
		return;
}



bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}