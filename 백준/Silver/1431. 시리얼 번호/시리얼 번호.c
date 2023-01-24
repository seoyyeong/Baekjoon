#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	char key[51] ;
}data;

int sumcmp(const data* a, const data* b) {
	char* na = (data*)a->key;
	char* nb = (data*)b->key;
	int a_sum = 0, b_sum = 0;
	int a_len = strlen(na), b_len = strlen(nb);
	

	for (int i = 0; i < a_len; i++) 
		if (*(na + i) >= '0' && *(na + i) <= '9')
			a_sum += (*(na + i) - 48);

	for (int i = 0; i < b_len; i++)
		if (*(nb + i) >= '0' && *(nb + i) <= '9')
			b_sum += (*(nb + i) - 48);

	return a_sum - b_sum;
}

int cmp(const data* a, const data* b) {
	char* na = (data*)a->key;
	char* nb = (data*)b->key;
	if (strlen(na) != strlen(nb))
		return strlen(na) - strlen(nb);
	else if (sumcmp(a, b) != 0)
		return sumcmp(a, b);
	else return strcmp(na, nb);
}

int main(void) {
	
	int n;
	scanf("%d", &n);
	data* arr = (data*)malloc(sizeof(data) * n);

	for (int i = 0; i < n; i++) 
		scanf("%s", &arr[i].key);
	
	qsort(arr, n, sizeof(data), cmp);

	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i].key);

	free(arr);

	return 0;
}