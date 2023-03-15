#include <stdio.h>

int main(void) {
	
	int n;
	char arr[1001];
	scanf("%d", &n);
	arr[1] = 'C';
	arr[2] = 'S';
	arr[3] = 'C';
	arr[4] = 'S';

	for (int i = 5; i <= n; i++) {
		if (arr[i - 1] == 'S' && arr[i - 3] == 'S' && arr[i - 4] == 'S') arr[i] = 'C';
		else arr[i] = 'S';
	}

	if (arr[n] == 'S') printf("SK");
	else printf("CY");
	return 0;
}