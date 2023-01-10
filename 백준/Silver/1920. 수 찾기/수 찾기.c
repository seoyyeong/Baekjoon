#include <stdio.h>
#include <stdlib.h>

int cmp(const int* a, const int* b) {
	return *(int*)a > *(int*)b;
}

int main(void) {
	int n, m, s;
	scanf("%d", &n);
	int arr[100000];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), cmp);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &s);	
		int mid, left = 0, right = n - 1;
		int flag = 0;
		while (right >= left) {
			mid = (left + right) / 2;
			if (s == arr[mid]) flag = 1;
			if (s < arr[mid]) right = mid - 1;
			else left = mid + 1;
		}
		printf("%d\n", flag);
	}
	return 0;

}