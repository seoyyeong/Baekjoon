#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000001


char s[10];

int rvs(char* c) {
	int len = strlen(c);
	for (int i = 0; i <= len / 2; i++) {
		if (c[i] != c[len - i - 1]) return 1;
	}
	return 0;
}

int main(void) {
	int n, tmp;
	scanf("%d", &n);
	if (n == 1) {
		printf("2");
		return 0;
	}

	int* prime = (int*)calloc(MAX, sizeof(int));
	for (int i = 2; i * i < MAX; i++) {
		tmp = i * 2;
		while (tmp < MAX) {
			prime[tmp] = 1;
			tmp += i;
		}
	}

	for (int i = n; i < MAX; i++) {
		if (prime[i] == 0) {
			sprintf(s, "%d", i);
			if (rvs(s) == 0) {
				printf("%d", i);
				free(prime);
				return 0;
			}
		}
	}
}