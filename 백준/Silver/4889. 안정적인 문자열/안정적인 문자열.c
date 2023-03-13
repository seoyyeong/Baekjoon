#include <stdio.h>
#include <string.h>
int top;
int cnt;
char stack[2000];

void init(void) {
	top = -1;
	cnt = 0;
}

void func(char c) {
	if (c == '}') {
		if (stack[top] == '{') {
			top--;
			return;
		}
		else {
			stack[++top] = '{';
			cnt++;
			return;
		}
	}else
		stack[++top] = '{';
	return;
}

int main(void) {
	int len, n = 1;
	char s[2001];
	while (1) {
		init();
		scanf("%s", s);
		if (s[0] == '-') break;
		else {
			len = strlen(s);
			for (int i = 0; i < len; i++) {
				func(s[i]);
			}
		}
		if (top > 0) 
			cnt += (top + 1) / 2;

		printf("%d. %d\n", n, cnt);
		n++;
	}

	return 0;
}