#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	char s[501];
}data;

int cmp(const void* a, const void* b)
{
	data *na = (data*)a;
	data *nb = (data*)b;
	char* ta = na->s;
	char* tb = nb->s;
	
	return strcmp(ta, tb);
}

int search(data* arr, char* s, int n) {
	int len = strlen(s);
	int left = 0;
	int right = n - 1;
	int mid;

	while (right >= left)
	{
		mid = (left + right) / 2;
		if (strncmp(arr[mid].s, s, len) == 0)
			return 1;

		else if (strncmp(arr[mid].s, s, len) > 0)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return 0;
}

int main(void)
{
	int n;
	int m;
	int cnt = 0;
	char t[501];
	data* arr;
	scanf("%d %d", &n, &m);
	arr = (data*)malloc(sizeof(data) * n);


	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i].s);
	}

	qsort(arr, n, sizeof(data), cmp);

	for (int i = 0; i < m; i++)
	{
		scanf("%s", t);
		cnt += search(arr, t, n);
	}

	printf("%d", cnt);
	return 0;
}