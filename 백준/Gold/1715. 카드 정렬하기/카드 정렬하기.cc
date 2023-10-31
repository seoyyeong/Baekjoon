#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	int temp;
	int a;
	int b;
	int cnt = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		pq.push(temp);
	}

	while (pq.size() > 1)
	{
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		cnt += a + b;
		pq.push(a + b);
	}

	printf("%d", cnt);

	return 0;
}
