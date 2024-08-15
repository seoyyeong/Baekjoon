#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main(void)
{
    int n;
    int cnt = 0;
    int time = -1;
    vector<P> v;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        v.push_back({ b,a });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (v[i].second >= time)
        {
            time = v[i].first;
            cnt++;
        }
    }
    cout << cnt;
}