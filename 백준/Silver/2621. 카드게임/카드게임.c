#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a>b)?a:b)
#define MIN(a, b) ((a<b)?a:b)

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int c145(char* c, int* n) {
	int flag1 = 0, flag2 = 0;
	for (int i = 1; i < 5; i++) {
		if (flag1 == 0 && c[i] != c[i - 1]) {
			flag1 = 1;
		}
		if (flag2 == 0 && n[i] - n[i - 1] != 1) {
			flag2 = 1;
		}
	}
	if (flag1 == 0 && flag2 == 0) return n[4] + 900;
	else if (flag1 == 1 && flag2 == 1) return 0;
	else if (flag1 == 0) return n[4] + 600;
	else return n[4] + 500;
}

int c236789(int* n, int* idx) {
	int t = 0;
	int flag2 = 0, flag3 = 0;
	for (int i = 1; i < 10; i++) {
		if (idx[i] == 4) return i + 800;
		if (idx[i] == 3) {
			flag3 = i;
			break;
		}
		if (idx[i] == 2) {
			flag2 = i;
			break;
		}
	}
	if (flag3 != 0) {
		for (int i = 1; i < 10; i++) {
			if (idx[i] == 2) return flag3 * 10 + i + 700;
		}
		return flag3 + 400;
	}
	if (flag2 != 0) {
		for (int i = 1; i < 10; i++) {
			if (idx[i] == 3) return i * 10 + flag2 + 700;
			if (i != flag2) {
				if (idx[i] == 2) return MAX(i, flag2) * 10 + MIN(i, flag2) + 300;
			}
		}
		return flag2 + 200;
	}
	return n[4] + 100;
}

int main(void) {
	char color[6];
	int num[5] = { 0 }, idx[10] = { 0 };
	int score = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%c", &color[i]);
		getchar();
		scanf("%d", &num[i]);
		getchar();
		idx[num[i]]++;
	}
	qsort(num, 5, sizeof(int), cmp);

	score = MAX(c145(color, num), score);
	score = MAX(c236789(num, idx), score);

	printf("%d", score);
	
	return 0;
}