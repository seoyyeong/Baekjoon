#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001

int n;
int arr[20];
int* check;

void cmb(int a, int num) {
	check[num] = 1;
	for (int i = a + 1; i < n; i++) {
		cmb(i, num + arr[i]);
	}
}

int main(void) {
	check = (int*)calloc(MAX, sizeof(int));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < n; i++) {
		cmb(i, arr[i]);
	}

	for (int i = 1; i < MAX; i++) {
		if (check[i] == 0) {
			printf("%d", i);
			break;
		}
	}

	free(check);
	check = NULL;
	return 0;
}