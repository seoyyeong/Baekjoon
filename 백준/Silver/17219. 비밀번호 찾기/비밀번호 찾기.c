#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	char addr[21];
	char pw[21];
}data;


int fcmp(const data* a, const data* b) {
	data na = *(data*)a;
	data nb = *(data*)b;
	return strcmp(na.addr, nb.addr);
}

int main(void) {
	int n, m;
	scanf("%d %d ", &n, &m);
	
	data* arr = (data*)malloc(sizeof(data) * n);
	for (int i = 0; i < n; i++) 
		scanf("%s %s", arr[i].addr, arr[i].pw);

	qsort(arr, n, sizeof(data), fcmp);
	
	for (int i = 0; i < m; i++) {
		char s[21];
		scanf("%s", s);
		int mid, left = 0, right = n - 1;
		while (right >= left) {
			mid = (left + right) / 2;
			char t[21];
			strcpy(t, arr[mid].addr);
			int cmp = strcmp(s, t);
			if (cmp == 0) {
				printf("%s\n", arr[mid].pw);
				break;
			}
			else if (cmp < 1) right = mid - 1;
			else left = mid + 1;
		}
	}

	free(arr);
	return 0;
}