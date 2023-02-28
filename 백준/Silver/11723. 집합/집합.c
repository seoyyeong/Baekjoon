#include <stdio.h>
#include <string.h>
#define MAX 20

int s[MAX];

void add(int a) {
	s[a - 1] = 1;
}

void rmv(int a) {
	s[a - 1] = 0;
}

void check(int a) {
	if (s[a - 1] == 1) printf("1\n");
	else printf("0\n");
}

void toggle(int a) {
	if (s[a - 1] == 1) s[a - 1] = 0;
	else s[a - 1] = 1;
}

void all(void) {
	for (int i = 0; i < MAX; i++)
		s[i] = 1;
}

void empty(void) {
	for (int i = 0; i < MAX; i++)
		s[i] = 0;
}

int main(void) {
	int m, t;
	char ch[10];
	scanf("%d", &m);
	empty();

	while (m--) {
		scanf("%s", ch);
		if (strcmp(ch, "add")==0) {
			scanf("%d", &t);
			add(t);
		}
		else if (strcmp(ch, "remove")==0) {
			scanf("%d", &t);
			rmv(t);
		}
		else if (strcmp(ch, "check")==0) {
			scanf("%d", &t);
			check(t);
		}
		else if (strcmp(ch, "toggle")==0) {
			scanf("%d", &t);
			toggle(t);
		}
		else if (strcmp(ch, "all")==0) all();
		else empty();
	}

	return 0;
}
