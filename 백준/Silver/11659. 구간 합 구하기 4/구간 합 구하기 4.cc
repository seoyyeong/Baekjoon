#include <iostream>


using namespace std;

int v[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int m;
    int temp;

    cin >> n >> m;
    v[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i + 1];
        v[i + 1] += v[i];
    }

    for (int i = 0; i < m; i++)
    {
        int start;
        int end;

        cin >> start >> end;

        cout << v[end] - v[start - 1] << '\n';
    }

    return 0;
}