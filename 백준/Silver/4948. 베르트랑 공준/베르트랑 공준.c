#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 246912

int main(void) {

	int n, cnt;
	int* arr = (int*)calloc(MAX + 1, sizeof(int));
	for (int i = 2; i <= sqrt(MAX); i++) {
		int t = i * 2;
		while (t <= MAX) {
			arr[t] = 1;
			t += i;
		}
	}

	while (1) {
		cnt = 0;
		scanf("%d", &n);
		if (n == 0) {
			free(arr);
			return 0;
		}
		if (n == 1) {
			printf("1\n");
			continue;
		}
		for (int i = n + 1; i <= n * 2; i++) {
			if (arr[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
	
}