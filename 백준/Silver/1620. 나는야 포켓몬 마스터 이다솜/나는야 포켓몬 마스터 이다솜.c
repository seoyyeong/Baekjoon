#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dex {
	int idx;
	char name[21];
}dex;

int cmp(const dex* a, const dex* b) {
	char* na = (char*)a->name;
	char* nb = (char*)b->name;
	return strcmp(na, nb);
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	dex *pokedex = (dex*)malloc(sizeof(dex)*n);
	for (int i = 0; i < n; i++) {
		pokedex[i].idx = i + 1;
		scanf("%s", pokedex[i].name);
	}

	dex* pokedex_s = (dex*)malloc(sizeof(dex) * n);

	for (int i = 0; i < n; i++) {
		pokedex_s[i].idx = pokedex[i].idx;
		strcpy(pokedex_s[i].name, pokedex[i].name);
	}
	memcpy(pokedex_s, pokedex, sizeof(pokedex));
	qsort(pokedex_s, n, sizeof(dex), cmp);

	for (int j = 0; j < m; j++) {
		char q[21];
		scanf("%s", q);

		if (q[0] >= '0' && q[0] <= '9') {
			int idx = atoi(q);
			printf("%s\n", pokedex[idx-1].name);
		}
		else {
			int mid, left = 0, right = n - 1;
			while (right>=left) {
				mid = (left + right) / 2;
				if (strcmp(pokedex_s[mid].name, q) == 0) break;
				else if (strcmp(pokedex_s[mid].name, q) > 0) right = mid - 1;
				else left = mid + 1;
			}
			printf("%d\n", pokedex_s[mid].idx);
		}
	}

	return 0;
}