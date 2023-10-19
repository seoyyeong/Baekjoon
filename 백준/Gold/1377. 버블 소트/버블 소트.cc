#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

int main(void)
{
	int n;
	int max = 0;
	p temp;
	vector<p>::iterator iter;
	scanf("%d", &n);

	vector<p> v(n, { 0,0 });

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp.first);
		temp.second = i;
		v[i] = temp;
	}

	stable_sort(v.begin(), v.end());
	iter = v.begin();

	for (int i = 0; i < n; i++)
	{
		if (iter->second - i > max)
		{
			max = iter->second - i;
		}
		iter++;
	}

	printf("%d", max + 1);
	return 0;
}