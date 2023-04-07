#include <stdio.h>
#include <string.h>

int main(void) {
	
	int cnt = 0;
	char L[11], R[11];
	scanf("%s %s", L, R);

	if (strlen(L) != strlen(R)) {
		printf("%d", cnt);
	}
	else {
		for (int i = 0; i < strlen(L); i++) {
			if (L[i] == R[i]) {
				if (L[i] == '8') cnt++;
			}
			else break;
		}

		printf("%d", cnt);
	}

	return 0;
}