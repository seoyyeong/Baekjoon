#include <stdio.h>
#define MAX 46

int search(int s, int* arr) {
	int mid, left = 0, right = MAX - 1;
	while (1) {
		mid = (left + right) / 2;
		if (arr[mid] > s && arr[mid - 1] <= s) {
			return arr[mid - 1];
		}
		else if (arr[mid] > s) right = mid - 1;
		else left = mid + 1;
	}
}

int main(void) {
	int t, n, tmp, top;
	scanf("%d", &t);

	int arr[MAX];
	int stack[20];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i < MAX; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (int i = 0; i < t; i++) {
		top = -1;
		scanf("%d", &n);

		while (n != 0) {
			stack[++top] = search(n, arr);
			n -= stack[top];
		}

		while (top != -1) {
			printf("%d ", stack[top--]);
		}
		printf("\n");
	}
	return 0;
}