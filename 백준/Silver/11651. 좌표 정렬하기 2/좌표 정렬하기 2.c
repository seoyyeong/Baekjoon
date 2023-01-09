#include <stdio.h>
#include <stdlib.h>

typedef struct coor {
	int x, y;
}coor;

int cmp(const coor *a, const coor *b) {
	coor i = *(coor*)a;
	coor j = *(coor*)b;

	if (i.y == j.y) return (i.x > j.x);
	else return (i.y > j.y);
}

int main(void) {
	int n;
	scanf("%d", &n);

	coor* arr = (coor*)malloc(sizeof(arr) * n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &arr[i].x, &arr[i].y);

	qsort(arr, n, sizeof(coor), cmp);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	free(arr);
	return 0;
}