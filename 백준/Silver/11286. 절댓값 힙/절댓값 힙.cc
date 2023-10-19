
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;


void func(p n)
{
	if (n.second == 0)
	{
		if (pq.size() == 0)
		{
			printf("0\n");

		}
		else
		{
			printf("%d\n", pq.top().second);
			pq.pop();
		}
	}
	else
	{
		pq.push(n);
	}

}

int main(void)
{
	int n;
	int temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		func({ abs(temp), temp});

	}

	return 0;
}