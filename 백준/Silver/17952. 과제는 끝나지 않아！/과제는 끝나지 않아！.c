#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	int score;
	int time;
}data;

int main(void) {

	int n, t, sum = 0;
	scanf("%d", &n);
	data* arr = (data*)malloc(sizeof(data) * n);
	int top = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t == 1) {
			top++;
			scanf("%d %d", &arr[top].score, &arr[top].time);
		}
		if (top >= 0) {
			arr[top].time--;			
			if (arr[top].time == 0) {
				sum += arr[top--].score;
			}
		}
	}

	printf("%d", sum);
	free(arr);
	return 0;
}