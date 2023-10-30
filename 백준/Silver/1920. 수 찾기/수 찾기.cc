#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vn;
vector<int> vm;
int n, m;

int Search(int num);

int main(void)
{
	int temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		vn.push_back(temp);
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		vm.push_back(temp);
	}

	sort(vn.begin(), vn.end());
	
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", Search(vm[i]));
	}


	return 0;
}

int Search(int num)
{
	int left;
	int mid;
	int right;

	left = 0;
	right = n - 1;

	while (right >= left)
	{
		mid = (right + left) / 2;

		if (vn[mid] == num)
			return 1;

		if (vn[mid] < num)
		{
			left = mid + 1;
		}

		if (vn[mid] > num)
		{
			right = mid - 1;
		}
	}

	return 0;
}