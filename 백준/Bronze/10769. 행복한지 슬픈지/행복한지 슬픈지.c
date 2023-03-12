#include <stdio.h>
#include <string.h>

int main(void) {
	int happy = 0, sad = 0, p = 0;
	char c, s[256];

	while (c = getchar()) {
		if (c == '\n') {
			s[p] = '\0';
			break;
		}
		else if (c == ' ') continue;
		else s[p++] = c;
	}


	for (int i = 0; i < p; i++) {
		if (s[i] == ':') {
			i++;
			if (s[i] == '-') {
				i++;
				if (s[i] == '(') sad++;
				else if (s[i] == ')') happy++;
			}
		}
	}

	if (happy == 0 && sad == 0) printf("none");
	else if (happy > sad) printf("happy");
	else if (happy == sad) printf("unsure");
	else printf("sad");
	
	return 0;
}