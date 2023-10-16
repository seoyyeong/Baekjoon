#include <iostream>

using namespace std;

int main(void)
{
	int cnt;
	int num;
	int ret = 0;

	cin >> cnt;

	getchar();
	for (int i = 0; i < cnt; i++)
	{
		num = getchar();
		ret += num - '0';
	}

	cout << ret << endl;
    
    return 0;
}