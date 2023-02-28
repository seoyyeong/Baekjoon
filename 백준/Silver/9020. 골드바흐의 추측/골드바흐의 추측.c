#include <stdio.h>
#include <math.h>
#define MAX 10000

int main(void) {

	int tmp, check[MAX + 1] = { 0 };
	for (int i = 2; i <= sqrt(MAX); i++) {
		tmp = i * 2;
		while (tmp <= MAX) {
			check[tmp] = 1;
			tmp += i;
		}
	}

	int prime[MAX], cnt = 0;
	for (int i = 2; i < MAX + 1; i++) 
		if (check[i] == 0) 
			prime[cnt++] = i;

	int t, n, m, flag;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		m = n / 2;
		if (check[m] == 0) {
			printf("%d %d\n", m, m);
		}
		else {
			int mid, left = 0, right = cnt - 1;
			while (right >= left) {
				mid = (left + right) / 2;
				if (prime[mid] == m) break;
				else if (prime[mid] > m) right = mid - 1;
				else left = mid + 1;
			}

			for (int i = mid; i >= 0; i--) {
				flag = 0;
				for (int j = mid; j < cnt; j++) {
					if (prime[i] + prime[j] == n) {
						printf("%d %d\n", prime[i], prime[j]);
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
			}
		}
	}
	
	return 0;
}
