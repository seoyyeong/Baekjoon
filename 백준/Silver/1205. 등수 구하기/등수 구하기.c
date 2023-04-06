#include <stdio.h>

int main(void) {
	
	int n, s, p, i, t = 1;
	int arr[50];
	scanf("%d %d %d", &n, &s, &p);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (n == 0) {
		printf("1");
	}

	else {
		p--;
		for (i = 0; i < n; i++) {
			if (arr[i] == s) {
				while (arr[i] == s && i < n - 1) {
					i++;
				}
			}
			if (arr[i] < s) {
				printf("%d", t);
				return 0;
			}
			else if (arr[i] > s) {
				t++;
			}
		}
		if (i > p)
			printf("-1");
		else
			printf("%d", t);
	}
	return 0;
}