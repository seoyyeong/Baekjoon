#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char vowel[6] = { 'a','e','i','o','u' };

int isvowel(char c) {
	for (int i = 0; i < 5; i++)
		if (c == vowel[i]) return 1;
	return 0;
}

int c1(char* s, int len) {
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (isvowel(s[i])) return 1;
	return 0;
}

int c2(char* s, int len) {
	int cnt = 0;
	char flag = 'v';
	for (int i = 0; i < len; i++) {
		if (flag == 'v') {
			if (isvowel(s[i])) cnt++;
			else {
				cnt = 1;
				flag = 'c';
			}
		}
		else {
			if (!isvowel(s[i])) cnt++;
			else {
				cnt = 1;
				flag = 'v';
			}
		}
		if (cnt >= 3) return 0;
	}
	return 1;
}

int c3(char* s, int len) {
	for (int i = 1; i < len; i++) {
		if (s[i] == s[i - 1]) {
			if (s[i] != 'e' && s[i] != 'o') return 0;
		}
	}
	return 1;
}

int main(void) {
	
	char s[21];
	while (1) {
		scanf("%s", s);
		if (strcmp(s, "end") == 0) return 0;
		int l = strlen(s);
		if (c1(s, l) == 1 && c2(s, l) == 1 && c3(s, l) == 1)
			printf("<%s> is acceptable.\n", s);
		else printf("<%s> is not acceptable.\n", s);
	}
	return 0;
}