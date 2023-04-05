#include <stdio.h>

int stack[500];
int top, ans;

void push(int n) {
	stack[++top] = n;
}

int pop(void) {
	return stack[top--];
}

void min(int n) {
	int t;
	int p = top;
	while (p > -1) {
		t = 0;
		if (n > stack[p]) {
			t = n - stack[p];
			ans += t;
		}
		stack[p--] += t;
	}
}
int main(void) {
	
	int h, w, t;
	int start = 0;
	top = -1;
	ans = 0;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < w; i++) {
		scanf("%d", &t);
		if (start <= t) {
			while (top > -1) {
				ans += start - pop();
			}
			start = t;
		}
		else {
			if (top > -1 && stack[top] < t) 
				min(t);
			push(t);
		}
	}
	if (top > -1)
		min(t);

	printf("%d", ans);

	return 0;
}
