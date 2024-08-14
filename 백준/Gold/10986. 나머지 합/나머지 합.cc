#include <iostream>

using namespace std;

long long arr[1000001];
long long mod[1000];

int main(void)
{
    long long n;
    long long m;
    long long cnt = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        arr[i] %= m;
        if (arr[i] == 0)
        {
            cnt++;
        }
        mod[arr[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (mod[i] > 1)
        {
            cnt += mod[i] * (mod[i] - 1) / 2;
        }
    }
    cout << cnt << '\n';

    return 0;
}