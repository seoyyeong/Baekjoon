#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char indexarr[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

typedef struct data {
	char num[5];
	char ch[11];
}data;

int cmp(const void* a, const void* b) {
	data na = *(data*)a;
	data nb = *(data*)b;
	char* sa = na.ch;
	char* sb = nb.ch;
	return strcmp(sa, sb);
}
void replace(char* src, char *dst) {
	char* p = dst;
	for (int i = 0;i < strlen(src);i++) {
		int n = src[i] - 48;
		strcpy(p, indexarr[n]);
		p += strlen(p);
	}
}

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	int a = n - m + 1;
	data* arr = (data*)malloc(sizeof(data) * a);

	for (int i = m;i <= n;i++) {
		sprintf(arr[i - m].num, "%d", i);
		replace(arr[i - m].num, arr[i - m].ch);
	}
	
	qsort(arr, a, sizeof(data), cmp);

	for (int i = 0;i < a;i++) {
		printf("%s ", arr[i].num);
		if (i % 10 == 9) printf("\n");
	}
	
	free(arr);
	return 0;
}
