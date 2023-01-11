#include <stdio.h>

int main(void) {

	int n, m, ans;
	int p, o, p_min = 1001, o_min = 1001;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &p, &o);
		if (p_min > p) p_min = p;
		if (o_min > o) o_min = o;
	}

	if ((n / 6 + 1) * p_min < n * o_min) ans = (n / 6 + 1) * p_min;
	else ans = n * o_min;

	if ((n / 6 * p_min + n % 6 * o_min) < ans) ans = n / 6 * p_min + n % 6 * o_min;

	printf("%d", ans);
	return 0;
}