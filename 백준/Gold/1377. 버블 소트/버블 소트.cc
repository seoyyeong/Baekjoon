#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;
vector<p> v;
int arr[500000];

int main(void)
{
	int n;
	int max = 0;
	p temp;
	vector<p>::iterator iter;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		temp.first = arr[i];
		temp.second = i;
		v.push_back(temp);
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