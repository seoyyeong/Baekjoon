#include <stdio.h>
#include <string.h>

int tail;

void push(char a[], char c) {
	a[++tail] = c;
}

char pop(char a[]) {
	char c = a[tail];
	a[tail--] = '\0';
	return c;
}

int main(void) {

	while (1) {
		int flag = 0, cnt1 = 0, cnt2 = 0;
		char c;
		char input[101] = " ";
		char check[101] = " ";
		tail = -1;

		while (1) {
			c = getchar();
			if (c == '\n') break;
			push(input, c);
		}
		if (strcmp(".", input) == 0) break;

		int l = strlen(input)-1;
		tail = -1;
		for (int i = 0; i < l; i++) {
			c = input[i];

			if (c == '[') 
				push(check, c);

			else if (c == '(') 
				push(check, c);

			else if (c == ')') {
				if (check[tail] != '(') {
					flag = 1;
					break;
				}
				pop(check);
			}
			else if (c == ']') {
				if (check[tail] != '[') {
					flag = 1;
					break;
				}
				pop(check);
			}	
		}
			if (tail!=-1) flag = 1;
			printf("%s\n", (flag == 0) ? "yes" : "no");
	}
	return 0;
}