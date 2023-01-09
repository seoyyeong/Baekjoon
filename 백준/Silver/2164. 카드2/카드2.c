#include <stdio.h>
#define MAX 500000

int head, tail;
int queue[MAX];

void push(int n) {
	queue[tail] = n;
	tail = ++tail % MAX;
}

void pop(void) {
	queue[head] = 0;
	head = ++head % MAX;
}

int main(void) {
	int n;
	head = 0, tail = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		push(i);

	while ((head+1)%MAX!=tail) {
		pop();
		push(queue[head]);
		pop();
	}

	printf("%d", queue[head]);
	return 0;
}