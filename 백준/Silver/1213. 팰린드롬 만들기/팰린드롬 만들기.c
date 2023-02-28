#include <stdio.h>

int main(void) {
	
	int t, mid = -1, flag = 0, check[26] = { 0 };
	char c;
	while ((c = getchar()) != '\n') 
		check[c - 65]++;
	
	for (int i = 0; i < 26; i++) {
		if (check[i] % 2 != 0) {
			if (flag != 0) {
				printf("I'm Sorry Hansoo");
				return 0;
			}
			else {
				mid = i;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (check[i] == 1) continue;
		t = check[i] / 2;
		for (int j = 0; j < t; j++) {
			printf("%c", i + 65);
			check[i]--;
		}
	}
	if (mid != -1) {
		printf("%c", mid + 65);
		check[mid]--;
	}
	for (int i = 25; i >= 0; i--) {
		while (check[i] != 0) {
			printf("%c", i + 65);
			check[i]--;
		}
	}
	return 0;
}