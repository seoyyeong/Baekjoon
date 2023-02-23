#include <stdio.h>

int check(char a) {
	if (a >= 'A' && a <= 'Z')
		return 1;
	else if (a >= 'a' && a <= 'z')
		return 1;
	else if (a >= '0' && a <= '9')
		return 1;
	else return 0;
}

int main(void) {

	char arr[5][16] = {0};
	for (int i = 0; i < 5; i++) 
		scanf("%s", arr[i]);
	
	int p = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (check(arr[j][i]) == 1)
				printf("%c", arr[j][i]);
		}
	}

	return 0;
}