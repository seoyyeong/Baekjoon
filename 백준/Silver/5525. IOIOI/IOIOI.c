#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char p[1000001], s[1000001];

int main(void) {
	
	int n, m, l, cnt = 0;
	char* t = s;
	scanf("%d %d %s",&n, &m, &s);
	p[0] = 'I';
	n = n * 2 + 1;
	for (int i = 1; i < n; i+=2) {
		p[i] = 'O';
		p[i + 1] = 'I';
	}
	p[n] = '\0';

	l = m - n;
	for (int i = 0; i <= l; i++) {
		if (strncmp(p, t, n) == 0) cnt++;
		t++;
	}

	printf("%d", cnt);

	return 0;
}
