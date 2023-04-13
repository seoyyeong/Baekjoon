#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int max = 0;
	int idx[26] = { 0 };
	char c;
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			idx[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (idx[i] > max) {
			max = idx[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (idx[i] == max) {
			printf("%c", i + 'a');
		}
	}

	return 0;
}