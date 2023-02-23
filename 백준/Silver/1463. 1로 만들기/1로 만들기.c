#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (a<b?a:b)

int main(void) {

	int x;
	scanf("%d", &x);
	int* arr = (int*)malloc(sizeof(int) * (x + 1));
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= x; i++) {
		if (i % 3 == 0) {
			if (i % 2 == 0)
				arr[i] = MIN(MIN(arr[i / 3], arr[i / 2]), arr[i - 1]) + 1;
			else
				arr[i] = MIN(arr[i / 3], arr[i - 1]) + 1;
		}
		else if (i % 2 == 0)
			arr[i] = MIN(arr[i / 2], arr[i - 1]) + 1;
		else arr[i] = arr[i - 1] + 1;
				
	}

	printf("%d", arr[x]);
    free(arr);
	return 0;
}
