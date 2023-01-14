#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	char s[1001];
	scanf("%s", s);
	int n = strlen(s);
	char* arr = (char*)malloc(sizeof(char) * n * (n + 1));

	for (int i = 0; i < n; i++)
		strcpy(&arr[i * (n + 1)], s + i);

	qsort(arr, n, sizeof(char) * (n + 1), strcmp);

	char *p = arr;
	for (int i = 0; i < n; i++) {
		printf("%s\n", p);
		p += (n + 1);
	}

	return 0;
}
