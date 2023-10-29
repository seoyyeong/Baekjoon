#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void)
{
	int n;
	int temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", v[i]);
	}

	return 0;
}