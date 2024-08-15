#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
queue<int> q;
vector<int> ans;
bool checked[300'001];
vector<int> depth;

void BFS(int num);

int main(void)
{
    int n;
    int m;
    int k;
    int x;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> x;

    for (int i = 0; i <= n; i++)
    {
        vector<int> temp;
        v.push_back(temp);
    }
    depth.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    BFS(x);

    depth[x] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] == k)
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }

    if (ans.size() == 0)
    {
        cout << -1 << '\n';
    }

    return 0;
}

void BFS(int num)
{
    int node;
    int f;

    depth[num] = 0;
    q.push(num);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); i++)
        {
            f = v[node][i];
            if (checked[f] == true)
            {
                if (depth[f] > depth[node] + 1)
                {
                    depth[f] = depth[node] + 1;
                }
            }
            else
            {
                checked[f] = true;
                depth[f] = depth[node] + 1;
                q.push(f);
            }
        }
    }

}