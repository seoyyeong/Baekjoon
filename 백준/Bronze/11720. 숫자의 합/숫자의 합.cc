#include <iostream>

using namespace std;

int main(void)
{
	int cnt;
	char str[101];
	int ret = 0;

	cin >> cnt >> str;

	for (int i = 0; i < cnt; i++)
	{
		ret += str[i] - '0';
	}

	cout << ret;

	return 0;
}