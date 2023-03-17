#include <stdio.h>

int main(void) {
	int n, t_w, t_l, cnt_w = 0, cnt_l = 0;
	char arr[100][101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < n; i++) {
		t_w = t_l = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') t_w++;
			else {
				if (t_w > 1) cnt_w++;
				t_w = 0;
			}
			if (arr[j][i] == '.') t_l++;
			else {
				if (t_l > 1) cnt_l++;
				t_l = 0;
			}
		}
		if (t_w > 1) cnt_w++;
		if (t_l > 1) cnt_l++;
	}
	printf("%d %d", cnt_w, cnt_l);
	return 0;
}