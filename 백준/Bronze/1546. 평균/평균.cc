#include <iostream>

double score[1000];

int main(void)
{
	int cnt;
	double max = 0;
	double m = 0;

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++)
	{
		scanf("%lf", &score[i]);
		if (score[i] > max)
		{
			max = score[i];
		}
	}
	
	for (int i = 0; i < cnt; i++)
	{
		m += score[i] / max * 100;
	}

	m /= cnt;

	printf("%lf", m);

	return 0;
}