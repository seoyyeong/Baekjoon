#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
	int n, t, cnt, max = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n - 1; i++) {
		t = arr[i];
		cnt = 0;
		for (int j = i + 1; j < n; j++) {
			if (t > arr[j])
				cnt++;
			else break;
		}
		if (cnt > max) max = cnt;
	}
	printf("%d", max);
    free(arr);
	return 0;
}