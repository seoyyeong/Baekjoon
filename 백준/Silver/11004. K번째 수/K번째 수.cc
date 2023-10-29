#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void)
{
	int n;
	int k;
	int temp;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	printf("%d", v[k - 1]);

	return 0;
}