#include <iostream>
#include <math.h>

bool Prime[1'000'001];

using namespace std;

int main(void)
{
    int m;
    int n;
    int max;
    int cnt = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    max = sqrt(n) + 1;
    Prime[1] = true;

    for (int i = 2; i <= max ; i++)
    {
        int temp = i;
        while (temp <= n)
        {
            temp += i;
            Prime[temp] = true;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (Prime[i] == false)
        {
            cout << i << '\n';
        }
    }


    return 0;
}