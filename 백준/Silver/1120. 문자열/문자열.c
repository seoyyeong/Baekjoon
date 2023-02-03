#include <stdio.h>
#include <string.h>

int main(void) {
	
	int min = 50;
	char s1[51], s2[51];
	scanf("%s %s", s1, s2);

	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);

	if (len_s1 >= len_s2) {
		for (int i = 0; i <= len_s1 - len_s2; i++) {
			int cnt = 0;
			for (int j = 0; j < len_s2; j++) 
				if (s1[j + i] != s2[j]) cnt++;
			if (cnt < min) min = cnt;
		}
	}
	else {
		for (int i = 0; i <= len_s2 - len_s1; i++) {
			int cnt = 0;
			for (int j = 0; j < len_s1; j++)
				if (s2[j + i] != s1[j]) cnt++;
			if (cnt < min) min = cnt;
		}

	}

	printf("%d", min);

	return 0;
} 