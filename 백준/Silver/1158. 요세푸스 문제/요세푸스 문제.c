#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n, k;
	scanf("%d %d", &n, &k);

	int* arr = (int*)malloc(sizeof(int) * n);
    
	for (int i = 0; i < n; i++) 
		arr[i] = i + 1;
    
	int cnt = n;
	int i = -1;
	printf("<");
	while (cnt > 0) {
		int flag = 0;
		while (flag < k) {
			i = (++i) % n;
			if (arr[i] != 0)
				flag++;
		}
		if (cnt > 1)
			printf("%d, ", arr[i]);
		else
			printf("%d>", arr[i]);
		arr[i] = 0;
		cnt--;
	}

	free(arr);
	return 0;
}