#include <stdio.h>

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	int n;
	int arr[500][500];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i ; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			arr[i][j] += cmp(arr[i + 1][j + 1], arr[i + 1][j]);
		}
	}

	printf("%d", arr[0][0]);

	return 0;
}