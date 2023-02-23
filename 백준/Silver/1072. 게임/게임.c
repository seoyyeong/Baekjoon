#include <stdio.h>
#include <math.h>

int main(void) {

	double x, y, z;
	scanf("%lf %lf", &x, &y);
	z = floor(100 * y / x);

	if (z >= 99) {
		printf("-1");
		return 0;
	}

	double mid, left = 1, right = x;
	while (right >= left) {
		mid = floor((left + right) / 2);
		double nz = floor(100 * (y + mid) / (x + mid));
		if (z < nz) {
			if (z == floor(100 * (y + mid - 1) / (x + mid - 1))) {
				printf("%.0lf", mid);
				return 0;
			}
			else right = mid - 1;
		}
		else if (z >= nz) left = mid + 1;
	}

}
