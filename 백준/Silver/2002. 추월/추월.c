#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	int idx;
	char s[10];
}data;

int cmp(const void* a, const void* b)
{
	data *na = (data*)a;
	data *nb = (data*)b;
	char* ta = na->s;
	char* tb = nb->s;
	return strcmp(ta, tb);
}

int bsearch_d(data* a, char* s, int n)
{
	int left = 0;
	int right = n - 1;
	int mid;

	while (right >= left)
	{
		mid = (left + right) / 2;
		if (strcmp(a[mid].s, s) == 0) return mid;
		else if (strcmp(a[mid].s, s) > 0) right = mid - 1;
		else left = mid + 1;
	}

	return -1;
}

int bsearch_n(int *arr, int s, int n)
{
	int left = 0;
	int right = n - 1;
	int mid;

	while (right >= left)
	{
		mid = (left + right) / 2;
		if (arr[mid] == s) return mid;
		else if (arr[mid] > s) right = mid - 1;
		else left = mid + 1;
	}

	return -1;
}

int main(void)
{
	int n;
	int nzidx;
	int nidx;
	int cnt = 0;
	int top = -1;
	int stack[1000];
	char nzTmp[10];
	scanf("%d", &n);

	data* arr = (data*)malloc(sizeof(data) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i].idx = i;
		stack[++top] = i;
		scanf("%s", arr[i].s);
	}
	qsort(arr, n, sizeof(data), cmp);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", nzTmp);
		nzidx = arr[bsearch_d(arr, nzTmp, n)].idx;
		if (nzidx != stack[0])
		{
			nidx = bsearch_n(stack, nzidx, top + 1);
			for (int j = nidx + 1; j <= top; j++) {
				stack[j - 1] = stack[j];
			}
			cnt++;
			top--;
		}
		else
		{
			for (int j = 1; j <= top; j++) {
				stack[j - 1] = stack[j];
			}
			top--;
		}

	}
	printf("%d", cnt);

	free(arr);
	return 0;
}
