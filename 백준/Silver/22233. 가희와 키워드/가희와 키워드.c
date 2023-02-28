#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char w[11];

typedef struct data {
	char key[11];
	int flag;
}data;

int cmp(const void* a, const void* b) {
	data na = *(data*)a;
	data nb = *(data*)b;
	char* as = na.key;
	char* bs = nb.key;
	return strcmp(as, bs);
}

int main(void) {
	int n, m, p, cnt;
	char c;
	scanf("%d %d", &n, &m);
	cnt = n;
	data* arr = (data*)malloc(sizeof(data) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s ", arr[i].key);
		arr[i].flag = 1;
	}

	qsort(arr, n, sizeof(data), cmp);

	while (m > 0) {
		p = 0;
		while (1) {
			c = getchar();
			if (c == ',') {
				break;
			}
			else if (c == '\n') {
				m--;
				break;
			}
			else w[p++] = c;
		}
		w[p] = '\0';

		int mid, left = 0, right = n - 1;

		while (right >= left) {
			mid = (left + right) / 2;
			if (strcmp(arr[mid].key, w) == 0) {
				if (arr[mid].flag == 1) {
					arr[mid].flag = 0;
					cnt--;
				}
				break;
			}
			else if (strcmp(arr[mid].key, w) > 0) right = mid - 1;
			else left = mid + 1;
		}
		if(c=='\n')
			printf("%d\n", cnt);
	}
	
	free(arr);
	return 0;
}