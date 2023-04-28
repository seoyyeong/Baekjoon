#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n1;
	int n2;
	char s1[10];
	char s2[10];

	scanf("%s %s", s1, s2);

	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] == '6') s1[i] = '5';
	}

	for (int i = 0; i < strlen(s2); i++) {
		if (s2[i] == '6') s2[i] = '5';
	}

	n1 = atoi(s1);
	n2 = atoi(s2);

	printf("%d ", n1 + n2);

	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] == '5') s1[i] = '6';
	}

	for (int i = 0; i < strlen(s2); i++) {
		if (s2[i] == '5') s2[i] = '6';
	}

	n1 = atoi(s1);
	n2 = atoi(s2);

	printf("%d ", n1 + n2);

	return 0;
}