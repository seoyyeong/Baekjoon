#include <stdio.h>
#include <stdlib.h>

int cmp(const int* a, const int* b) {
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*) a == *(int*)b) return 0;
	else return -1;
}
int main(void) {
	
	int n, s = 0;
	int a[50], b[50];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	qsort(a, n, sizeof(int), cmp);

	int cnt = 0;
	while (cnt++ != n) {
		int max = 0, maxindex = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] > max) {
				max = b[i];
				maxindex = i;
			}
		}
		s += a[cnt - 1] * max;
		b[maxindex] = -1;
	}

	printf("%d", s);
	return 0;
}