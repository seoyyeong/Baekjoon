#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000001

int main(void) {
	int n, a, b, t;
	int* arr = (int*)calloc(MAX, sizeof(int));

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < sqrt(MAX); i++) {
		t = i * 2;
		while (t < MAX) {
			arr[t] = 1;
			t += i;
		}
	}

	while (1) {
		a = 0, b = MAX;
		scanf("%d", &n);
		if (n == 0) break;
		t = n;
		while (1) {
			while (arr[t] == 1 || arr[n - t] == 1) {
				t--;
			}
			a = n - t;
			b = t;
			if (a > b || a < 0) {
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			else if (a + b == n) {
				printf("%d = %d + %d\n", n, a, b);
				break;
			}
		}
	}
	
	free(arr);
	return 0;
}