#include <stdio.h>
#include <stdlib.h>

int tail;
int stack[100000];

void push(int n) {
	stack[++tail] = n;
}

int pop(void) {
	int i = stack[tail];
	stack[tail--] = 0;
	return i;
}

int main(void) {

	int n, input, t, cnt = 0, num = 0, check[100001] = { 0 };
	char ans[400000];

	scanf("%d", &n);
	tail = -1;
	while (num < n) {
		scanf("%d", &input);

		if (stack[tail] != input) {
			if (check[input] != 0) {
				printf("NO");
				return 0;
			}
			for (int i = 1; i <= input; i++) 
				if (check[i] == 0) {
					t = i;
					break;
				}
			
			for (int i = t; i <= input; i++) {
				if (check[i] != 0 || i < 1) continue;
				push(i);
				ans[cnt++] = '+';
				check[i] = 1;
			}
		}
		t = pop();
		ans[cnt++] = '-';
		check[t] = 2;
		num++;
	}
	ans[cnt] = '\0';

	for (int i = 0; i < cnt; i++) {
		printf("%c\n", ans[i]);
	}

	return 0;
}