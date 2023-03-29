#include <stdio.h>
#include <math.h>

long long cmp(const long long a, const long long b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	long long ans;
	long long x, y, w, s;
	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);


	if (w * 2 > s) {
		if (w < s)
			ans = abs(x - y) * w + cmp(x, y) * s;
		else {
			ans = cmp(x, y) * s;
			if (abs(x - y) % 2 == 0) 
				ans += abs(x - y) * s;
			else 
				ans += (abs(x - y) - 1) * s + w;	
		}
	}
	else if (w * 2 <= s) 
		ans = (x + y) * w;

	printf("%lld", ans);

	return 0;
}
