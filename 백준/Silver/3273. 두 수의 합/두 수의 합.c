#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	int na = *(int*)a;
	int nb = *(int*)b;
	return na - nb;
}

int main(void) {
	
	int n, x, cnt = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &x);

	qsort(arr, n, sizeof(int), cmp);

	for (int j = 0; j < n; j++) {
		int mid, left = j, right = n - 1;
		while (right >= left) {
			mid = (left + right) / 2;
			int sum = arr[j] + arr[mid];
			if (sum == x) {
				if (mid != j)
					cnt++;
				break;
			}
			else if (sum > x) right = mid - 1;
			else left = mid + 1;
		}
	}
	printf("%d", cnt);
	free(arr);
	return 0;
}