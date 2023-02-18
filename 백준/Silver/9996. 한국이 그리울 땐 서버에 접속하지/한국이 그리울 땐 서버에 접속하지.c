#include <stdio.h>
#include <string.h>

int start_len, end_len, name_len;
char start[99], end[99];
char name[101];

int check(void) {
	if (start_len + end_len > name_len) return 0;
	char* s_p = start, * e_p = end + end_len - 1;
	char* name_p = name;
	while (*s_p) {
		if (*s_p != *name_p) return 0;
		s_p++;
		name_p++;
	}
	name_p = name + name_len - 1;
	while (*e_p) {
		if (*e_p != *name_p) return 0;
		e_p--;
		name_p--;
	}
	return 1;
}

int main(void) {

	int n;
	char c;
	int i = 0, j = 0;
	scanf("%d ", &n);

	while ((c = getchar()) != '*')
		start[i++] = c;
	start[i] = '\0';

	while ((c = getchar()) != '\n')
		end[j++] = c;
	end[j] = c;

	start_len = i;
	end_len = j;

	for (int i = 0;i < n;i++) {
		scanf("%s", name);
		name_len = strlen(name);
		if (check() == 1) printf("DA\n");
		else printf("NE\n");
	}

	return 0;
}