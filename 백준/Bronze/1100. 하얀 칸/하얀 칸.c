#include <stdio.h>

int main(void) {
	int n = 0;
	char arr[8][9];
	for (int i = 0; i < 8; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && arr[i][j] == 'F')
					n++;
			}
			else {
				if (j % 2 != 0 && arr[i][j] == 'F')
					n++;
			}
		}
	}
	printf("%d", n);

	return 0;
}