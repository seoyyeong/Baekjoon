#include <stdio.h>
#include <stdlib.h>
#define MAX 101

void boy(int n, int *arr, int l) {
	for (int i = n; i <= l; i+=n) {
		arr[i] = !arr[i];
	}
}

void girl(int n, int* arr, int l) {
	int left = n - 1, right = n + 1;
	arr[n] = !arr[n];
	while (left >= 0 && right <= l) {
		if (arr[left] != arr[right]) break;
		else {
			arr[left] = !arr[left];
			arr[right] = !arr[right];
			left--;
			right++;
		}
	}
}


int main(void) {
	int n, t, s, m;
	int arr[MAX];
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d ", &arr[i]);
	}
	scanf("%d ", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &s, &m);
		if (s == 1) boy(m, arr, n);
		else girl(m, arr, n);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
		if (i % 20 == 0) printf("\n");
	}

	return 0;
}