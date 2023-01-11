#include <stdio.h>
#include <string.h>

int main(void) {

	int cnt = 0, t = 0;
	char c = 0, arr[2501], src[50];
	char* a = arr, * s = src;

	while ((c = getchar()) != '\n') {
		if (c == ' ') *(a++) = '1';
		else *(a++) = c;
	}
	*a = '\0';

	while ((c = getchar()) != '\n') {
		if (c == ' ') *(s++) = '1';
		else *(s++) = c;
	}
	*s = '\0';

	a = arr, s = src;
	while (*a) {
		if (strncmp(a, s, strlen(src)) == 0) {
			cnt++;
			a += (int)strlen(src);
		}
		else a++;
	}
	printf("%d", cnt);

	return 0;
}