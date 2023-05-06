#include <stdio.h>

int arr[100000];

int gcd(int a, int b)
{
	int t;
	while (a) {
		if (b == 0) break;
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}


int main(void)
{

	int n;
	int d;
	int t;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	d = gcd(arr[1] - arr[0], arr[2] - arr[1]);
	for (int i = 3; i < n; i++)
		d = gcd(d, arr[i] - arr[i - 1]);


	for (int i = 0; i < n - 1; i++) {
		t = arr[i];
		while (t + d != arr[i + 1])
		{
			cnt++;
			t += d;
		}

	}

	printf("%d", cnt);
	return 0;
}