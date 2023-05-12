#include <stdio.h>

int main(void)
{
	int n;
	int m;
	int j;
	int t;
	int arr = 0;
	int mov = 0;
	scanf("%d %d", &n, &m);
	scanf("%d", &j);

	for (int i = 0; i < m; i++)
		arr = arr << 1 | 1;
	
	arr = arr << (10 - m);

	for (int i = 0; i < j; i++)
	{
		scanf("%d", &t);
		t = 1 << (10 - t);
		while ((t & arr) == 0) {
			if (arr < t) {
				arr <<= 1;
				mov++;
			}
			else {
				arr >>= 1;
				mov++;
			}
		}
	}
	
	printf("%d", mov);

	return 0;
}