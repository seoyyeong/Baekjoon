#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;


int main(void)
{
	int n;
	int l;
	int temp;
	int range;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		pq.push({ temp, i });

		range = i - l;
		while (pq.top().second <= range)
		{
			pq.pop();
		}

		cout << pq.top().first << ' ';
	}

	return 0;
}