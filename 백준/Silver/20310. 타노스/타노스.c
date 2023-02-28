#include <stdio.h>

int main(void) {
	int cnt[2] = { 0 };
	char c;

	while ((c = getchar()) != '\n') 
		cnt[c - 48]++;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < cnt[i] / 2; j++) {
			printf("%d", i);
		}
	}
	return 0;
}
