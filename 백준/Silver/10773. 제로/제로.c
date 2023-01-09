#include <stdio.h>

int tail;
int stack[100000];

void push(int n) {
	stack[++tail] = n;
}

int pop(void) {
	int i = stack[tail--];
	return i;
}

int main(void) {

	int k, t, sum=0;
	tail = -1;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &t);
		if (t != 0) {
			push(t);
			sum += t;
		}
		else {
			sum -= pop();
		}
	}

	printf("%d", sum);
	return 0;
}