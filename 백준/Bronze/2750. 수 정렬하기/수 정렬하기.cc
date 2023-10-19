#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int temp;
	vector<int> arr;
	vector<int>::iterator iter;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (iter = arr.begin(); iter != arr.end(); ++iter)
	{
		printf("%d\n", *iter);
	}

	return 0;
}