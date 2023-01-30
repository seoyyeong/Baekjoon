#include <stdio.h>
#include <stdlib.h>

void j2c(const char* s) {
	char* p = s;
	while (*p) {
		if (*p >= 'A' && *p <= 'Z')
			printf("_%c", *p + 32);
		else
			printf("%c", *p);
		p++;
	}
}

void c2j(const char* s) {
	char* p = s;
	while (*p) {
		if (*p == '_') {
			p++;
			printf("%c", *p - 32);
		}
		else
			printf("%c", *p);
		p++;
	}
}


int main(void) {
	char c, flag = '0';
	char arr[101];
	int i = 0;
	while ((c = getchar()) != '\n') {
		if (c >= 'A' && c <= 'Z') {
			if (flag == 'c') {
				printf("Error!");
				return 0;
			}
			flag = 'j';
		}
		else if (c == '_') {
			if (flag == 'j') {
				printf("Error!");
				return 0;
			}
			if (arr[i - 1] == '_') {
				printf("Error!");
				return 0;
			}
			flag = 'c';
		}
		arr[i++] = c;
	}
	arr[i] = '\0';
	
	if (!(arr[0] >= 'a' && arr[0] <= 'z')||arr[i-1] == '_') {
		printf("Error!");
		return 0;
	}

	if (flag == '0')
		printf("%s", arr);

	else if (flag == 'c')
		c2j(arr);
	else
		j2c(arr);

	return 0;
}