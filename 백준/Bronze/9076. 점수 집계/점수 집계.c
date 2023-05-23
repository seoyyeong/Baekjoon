#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b) return 1;
	else return -1;
}

int main(void)
{
	int t;
	int arr[5];

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[j]);
		
		qsort(arr, 5, sizeof(int), cmp);
		if (arr[3] - arr[1] >= 4)
			printf("KIN\n");
		else printf("%d\n", arr[1] + arr[2] + arr[3]);
	}
	return 0;
}
