#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	char* arr = (char*)malloc(sizeof(char) * (n + 1));

	arr[1] = 's';
	arr[2] = 'c';
	arr[3] = 's';
	arr[4] = 's';

	for (int i = 5; i <= n; i++) {
		if (arr[i - 1] == 's' && arr[i - 3] == 's' && arr[i - 4] == 's')
			arr[i] = 'c';
		else arr[i] = 's';
	}

	if (arr[n] == 's') printf("SK");
	else printf("CY");

	free(arr);
	return 0;
}