#include <stdio.h>
#include <string.h>

char rot(char c) {
	if (c >= 'a' && c <= 'z') {
		if (c + 13 > 'z') return 'a' + (c + 12 - 'z');
		else return c + 13;
	}
	if (c >= 'A' && c <= 'Z') {
		if (c + 13 > 'Z') return 'A' + (c + 12 - 'Z');
		else return c + 13;
	}
	else return c;
}

int main(void) {
	
	char s[100];
	gets(s);
	for (int i = 0; i < strlen(s); i++)
		printf("%c", rot(s[i]));

	return 0;
}
