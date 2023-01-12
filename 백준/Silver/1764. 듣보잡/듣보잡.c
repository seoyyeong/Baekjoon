#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arr {
	char name[21];
	int flag;
}arr;

int cmp(const void* a, const void* b) {
	arr na = *(arr*)a;
	arr nb = *(arr*)b;
	return strcmp(na.name, nb.name);

}

int main(void) {
	int n, m, cnt = 0;
	char d[21];
	
	scanf("%d %d", &n, &m);

	arr* b = (arr*)malloc(sizeof(arr) * n);

	for (int i = 0; i < n; i++) 
		scanf("%s", b[i].name);
	
	qsort(b, n, sizeof(arr), cmp);

	for (int i = 0; i < m; i++) {
		scanf("%s", &d);
		int mid, left = 0, right = n - 1;
		while (right >= left) {
			mid = (left + right) / 2;
			if (strcmp(b[mid].name, d) == 0) {
				b[mid].flag = 1;
				cnt++;
				break;
			}
			else if (strcmp(b[mid].name, d) > 0)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	printf("%d\n", cnt);

	for (int i = 0; i < n; i++) {
		if (b[i].flag == 1)
			printf("%s\n", b[i].name);
	}

	free(b);
	return 0;
}