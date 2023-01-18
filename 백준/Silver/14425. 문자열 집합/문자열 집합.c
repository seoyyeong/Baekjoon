#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str {
	char s[501];
}str;

int main(void) {
	
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	str *arr = (str*)malloc(sizeof(str) * n);

	for (int i = 0; i < n; i++)
		scanf("%s", arr[i].s);

	qsort(arr, n, sizeof(str), strcmp);

	for (int i = 0; i < m; i++) {
		char c[501];
		scanf("%s", c);

		int mid, left = 0, right = n - 1;
		while (right >= left) {
			mid = (left + right) / 2;
			if (strcmp(arr[mid].s, c) == 0) {
				cnt++;
				break;
			}
			else if (strcmp(arr[mid].s, c) >= 0)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	printf("%d", cnt);
	free(arr);
	return 0;
}