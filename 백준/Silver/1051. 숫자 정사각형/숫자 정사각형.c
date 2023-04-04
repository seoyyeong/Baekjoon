#include <stdio.h>
#define MAX 50
int arr[MAX][MAX];


int main(void) {
	int n, m, t, max = 1;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			t = 1;
			while (i + t < n && j + t < m) {
				if (arr[i][j] == arr[i + t][j] && arr[i][j] == arr[i][j + t] && arr[i][j] == arr[i + t][j + t]) {
					max = (max > (t + 1) * (t + 1)) ? max : (t + 1) * (t + 1);
				}
				t++;
			}
		}
	}

	printf("%d", max);

	return 0;
}