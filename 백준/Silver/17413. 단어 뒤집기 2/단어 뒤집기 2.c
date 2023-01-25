#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* __strrev(char* s) {
	int n = strlen(s);
	char* e = s + n - 1;
	for (int i = 0; i < n / 2; i++) {
		char t = *s;
		*(s++) = *e;
		*(e--) = t;
	}
	return s - n / 2;
}

int main(void) {

	int flag = 0;
	while (1) {
		char c;
		char *s = (char*)malloc(sizeof(char) * 100001);
		char *p = s;
		if (flag == 0) {
			while (1) {
				c = getchar();
				if (c == ' ' || c == '\n') {
					*(p++) = '\0';
					printf("%s", __strrev(s));
					break;
				}
				else if (c == '<') {
					*p = '\0';
					printf("%s", __strrev(s));
					flag = 1;
					break;
				}
				*(p++) = c;
			}
			if(flag == 0) printf(" ");
		}

		else {
			printf("<");
			while (1) {
				c = getchar();
				*(p++) = c;
				if (c == '>') {
					*p = '\0';
					break;
				}
			}
			printf("%s", s);
			flag = 0;
		}
		if (c == '\n') break;
		free(s);
	}
	return 0;
	
}