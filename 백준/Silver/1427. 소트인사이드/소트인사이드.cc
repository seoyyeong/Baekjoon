#include <iostream>
#include <cstring>

int cmp(const void* a, const void* b);

int main(void)
{
	char arr[11];
	scanf("%s", arr);
	qsort(arr, strlen(arr), sizeof(char), cmp);
	printf("%s", arr);

}

int cmp(const void* a, const void* b)
{
	return *(char*)b - *(char*)a;
}