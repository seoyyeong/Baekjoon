#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int l, cnt = 0, p = 0;
	char s[51];
	char ans[51];
	scanf("%s", s);
	l = strlen(s);
	for (int i = 0; i <= l; i++) {
		if (s[i] != 'X') {
			while (cnt != 0) {
				if (cnt >= 4) {
					strcpy(ans + p, "AAAA");
					p += 4;
					cnt -= 4;
				}
				else if (cnt == 2) {
					strcpy(ans + p, "BB");
					p += 2;
					cnt -= 2;
				}
				else {
					printf("-1");
					return 0;
				}
			}

			ans[p++] = '.';
		}
		else {
			cnt++;
		}
	}

	ans[l] = '\0';
	printf("%s", ans);

	return 0;
}