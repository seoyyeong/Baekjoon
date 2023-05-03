#include <stdio.h>


int main(void)
{

	int e;
	int s;
	int m;
	scanf("%d %d %d", &e, &s, &m);

	int ne = 1;
	int ns = 1;
	int nm = 1;
	int y = 1;

	while (1)
	{
		if (nm == m && ns == s && ne == e) break;

		ne++;
		ns++;
		nm++;

		if (nm > 19) {
			nm = 1;
		}
		if (ns > 28) {
			ns = 1;
		}
		if (ne > 15) {
			ne = 1;
		}
		
		y++;
		
	}

	printf("%d", y);
	return 0;
}