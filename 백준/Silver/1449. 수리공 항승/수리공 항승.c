#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) return 1;
	else return -1;
}

int main(void) {
	
	int n, l, t = 0, cnt = 1;
	int arr[1000];
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), cmp);

	for (int i = 1; i < n; i++) {
		if (l - (arr[i] - arr[t] + 1) >= 0) continue;
		else {
			t = i;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}