#include <stdio.h>
#include <stdlib.h>

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	int n, t = 1, max = 1;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) t++;
		else {
			max = cmp(t, max);
			t = 1;
		}
	}

	max = cmp(t, max);
	t = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i - 1]) t++;
		else {
			max = cmp(t, max);
			t = 1;
		}
	}
	max = cmp(t, max);

	printf("%d", max);
	free(arr);
	return 0;
}