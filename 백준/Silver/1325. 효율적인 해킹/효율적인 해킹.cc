#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<bool> checked;
vector<int> cnt;
queue<int> q;

void BFS(int num);

int main(void)
{
    int n;
    int m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    checked.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        vector<int> temp;
        v.push_back(temp);
        cnt[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;

        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        fill(checked.begin(), checked.end(), false);
        BFS(i);
    }

    int max = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > max)
        {
            max = cnt[i];
            ans = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == max)
        {
            cout << i << ' ';
        }
    }
    return 0;
}

void BFS(int num)
{
    int node;
    q.push(num);
    checked[num] = true;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (int i = 0; i < v[node].size(); i++)
        {
            int temp = v[node][i];
            if (checked[temp] == false)
            {
                checked[temp] = true;
                q.push(temp);
                cnt[num]++;
            }
        }
    }
}