#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	char key[101];
	int cnt;
}data;

int cmp(const data* a, const data* b) {
	char* na = a->key;
	char* nb = b->key;
	return strcmp(na, nb);
}

int main(void) {
	int n, cnt = 0;
	scanf("%d\n", &n);
	data* arr = (data*)malloc(sizeof(data) * n);

	for (int i = 0; i < n; i++) {
		char c;
		while (1) {
			c = getchar();
			if (c == '.') {
				scanf("%s", arr[i].key);
				arr[i].cnt = 1;
				break;
			}
		}
	}


	if (n == 1) {
		printf("%s %d", arr[0].key, n);
		return 0;
	}

	qsort(arr, n, sizeof(data), cmp);

	int i = 0, j = 1;
	while (1) {
		if (i == n - 1 || j > n - 1) {
			printf("%s %d\n", arr[i].key, arr[i].cnt);
			break;
		}
		if (strcmp(arr[i].key, arr[j].key) == 0) {
			arr[i].cnt++;
			j++;
		}

		else {
			printf("%s %d\n", arr[i].key, arr[i].cnt);
			i = j;
			j = i + 1;
		}
	}

	free(arr);
	return 0;
}