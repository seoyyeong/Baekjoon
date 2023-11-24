#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;


int main(void)
{
	int n;
	int m;
	int cnt = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		s.insert(temp);
	}

	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;

		if (s.find(temp) != s.end())
		{
			cnt++;
		}

	}

	printf("%d", cnt);
}
