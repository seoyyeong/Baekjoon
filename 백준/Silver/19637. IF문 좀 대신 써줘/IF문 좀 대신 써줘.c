#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	char name[12];
	int key;
}data;


int main(void) {
	int n, m;
	scanf("%d %d\n", &n, &m);
	data* arr = (data*)malloc(sizeof(data) * n);
	for (int i = 0; i < n; i++)
		scanf("%s %d\n", arr[i].name, &arr[i].key);
	
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		int mid, left = 0, right = n - 1;
		while (1) {
			mid = (left + right) / 2;
			if (mid == 0 && arr[mid].key >= t) {
				printf("%s\n", arr[mid].name);
				break;
			}
			else if (arr[mid].key < t && arr[mid + 1].key >= t) {
				printf("%s\n", arr[mid + 1].name);
				break;
			}
			else if (arr[mid].key < t)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	free(arr);
	return 0;
}