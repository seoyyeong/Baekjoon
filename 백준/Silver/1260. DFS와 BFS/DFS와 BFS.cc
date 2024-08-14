#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> vt;
queue<int> q;
bool checked[1001];

void DFS(int num);
void BFS(int num);

int main(void)
{
    int n;
    int m;
    int v;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;
    vt.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp;
        vt.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(vt[i].begin(), vt[i].end());
    }

    DFS(v);
    cout << '\n';

    for (int i = 0; i <= n; i++)
    {
        checked[i] = false;
    }
    BFS(v);
    cout << '\n';

    return 0;
}

void DFS(int num)
{
    if (checked[num] == true)
    {
        return;
    }
    checked[num] = true;
    cout << num << ' ';

    for (int i = 0; i < vt[num].size(); i++)
    {
        DFS(vt[num][i]);
    }

}

void BFS(int num)
{
    q.push(num);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        if (checked[temp] == false)
        {
            checked[temp] = true;
            cout << temp << ' ';

            for (int i = 0; i < vt[temp].size(); i++)
            {
                q.push(vt[temp][i]);
            }
        }
    }
}