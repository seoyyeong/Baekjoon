#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> arr;
	int n;
	int temp;
	int ans = 0;

	scanf("%d", &n);
	arr.push_back(0);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i <= n; i++)
	{
		arr[i] += arr[i - 1];
		ans += arr[i];
	}

	printf("%d", ans);

	return 0;
}