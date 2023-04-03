#include <stdio.h>

int arr[500000];
int stack[500000][2];
int top;

void push(int n, int idx) {
	top++;
	stack[top][0] = n;
	stack[top][1] = idx;
}


int main(void) {
	int n, flag;
	top = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("0 ");
	push(arr[0], 0);

	for (int i = 1; i < n; i++) {
		while (arr[i] >= stack[top][0]) {
			if (top == -1)
				break;
			top--;
		}
		if (top == -1) printf("0 ");
		else printf("%d ", stack[top][1]+1);
		push(arr[i], i);
	}

	return 0;
}
