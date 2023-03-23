#include <stdio.h>

int main(void) {
	int n;
	int arr[46] = { 0,1,1, };
	scanf("%d", &n);

	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%d", arr[n]);

	return 0;
}
