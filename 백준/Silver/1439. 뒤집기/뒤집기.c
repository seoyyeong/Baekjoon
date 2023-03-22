#include <stdio.h>

int main(void) {
	
	char t, c;
	int flag;
	int cnt[2] = { 0 };
	
	c = getchar();
	flag = c - '0';
	cnt[flag]++;
	t = c;
	while (c!='\n') {
		c = getchar();
		if (c != t) {
			cnt[flag]++;
			flag = !flag;
		}
		t = c;
	}

	printf("%d", (cnt[0]<cnt[1]?cnt[0]:cnt[1]));
	return 0;
}
