#include <iostream>


char pw[1000001];
int pwcnt[4];
int check[4];
enum CHAR { A = 0, C, G, T };

bool cmp(void);

int main(void)
{
	int s;
	int p;
	int idx;
	int idx_end;
	
	
	int cnt = 0;

	scanf("%d %d %s", &s, &p, pw);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &pwcnt[i]);
	}

	for (idx = 0; idx < p; idx++)
	{
		if (pw[idx] == 'A')
			check[A]++;
		else if (pw[idx] == 'C')
			check[C]++;
		else if (pw[idx] == 'G')
			check[G]++;
		else if (pw[idx] == 'T')
			check[T]++;
	}

	if (cmp())
		cnt++;
	
	idx = 0;

	while (idx < s - p)
	{
		if (pw[idx] == 'A')
			check[A]--;
		else if (pw[idx] == 'C')
			check[C]--;
		else if (pw[idx] == 'G')
			check[G]--;
		else if (pw[idx] == 'T')
			check[T]--;

		idx++;
		idx_end = idx + p - 1;

		if (pw[idx_end] == 'A')
			check[A]++;
		else if (pw[idx_end] == 'C')
			check[C]++;
		else if (pw[idx_end] == 'G')
			check[G]++;
		else if (pw[idx_end] == 'T')
			check[T]++;


		if (cmp())
			cnt++;

	}

	printf("%d", cnt);

	return 0;
}

bool cmp(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (pwcnt[i] > check[i])
			return false;
	}
    
	return true;
}