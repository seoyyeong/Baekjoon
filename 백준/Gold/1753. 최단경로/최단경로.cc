#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> P;
vector<vector<P>> vec;
priority_queue<P, vector<P>, greater<P>> q;
bool checked[20001];
int depth[20001];
int v;
int e;
int k;

void BFS(int num);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e;

    cin >> v >> e >> k;

    vec.resize(v + 1);
    for (int i = 0; i <= v; i++)
    {
        vector<P> temp;
        vec.push_back(temp);
        depth[i] = INT_MAX;
    }

    depth[k] = 0;

    for (int i = 0; i < e; i++)
    {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        vec[a].push_back({ b,c });
    }

    BFS(k);

    for (int i = 1; i <= v; i++)
    {
        if (checked[i]==false)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << depth[i] << '\n';
        }
    }
    return 0;
}

void BFS(int num)
{
    P node;
    int idx;
    q.push({ 0, num });

    while (!q.empty())
    {
        node = q.top();
        idx = node.second;
        q.pop();

        if (checked[idx] == true)
        {
            continue;
        }
        checked[idx] = true;

        for (int i = 0; i < vec[idx].size(); i++)
        {
            int next = vec[idx][i].first;
            int dist = vec[idx][i].second;

            if (depth[next] > depth[idx] + dist)
            {
                depth[next] = depth[idx] + dist;
                q.push({ depth[next], next });
            }

        }


    }
}
