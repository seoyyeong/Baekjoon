#include <stdio.h>

int main(void) {
	
	int n, k;
	int arr[100000];
	int t = 0, ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < k; i++) {
		ans += arr[i];
	}

	t = ans;
	for (int i = k; i < n; i++) {
		t = t - arr[i - k] + arr[i];
		if (ans < t) ans = t;
	}

	printf("%d", ans);
	return 0;
}
