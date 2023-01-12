#include <stdio.h>

int main(void) {

	int l, hash=0;
	char t;
	scanf("%d\n", &l);

	for (int i = 0; i < l; i++) {
		int m = 1;
		scanf("%c", &t);
		t -= 96;
		for (int j = 0; j < i; j++) 
			m *= 31;
		hash += t * m;
	}

	printf("%d", hash);
	return 0;
}