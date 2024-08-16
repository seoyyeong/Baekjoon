#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;


bool ans;
char checked[20001];
char visited[20001];
void DFS(int num, vector<vector<int>>& vec);

int main(void)
{
    int k;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        vector<vector<int>> vec;
        int v;
        int e;

        ans = true;
        memset(checked, 0, 20001);
        memset(visited, 0, 20001);

        cin >> v >> e;

        for (int j = 0; j <= v; j++)
        {
            vector<int> temp;
            vec.push_back(temp);
        }

        for (int j = 0; j < e; j++)
        {
            int a;
            int b;
            cin >> a >> b;

            vec[a].push_back(b);
            vec[b].push_back(a);

        }
        for (int i = 1; i <= v; i++)
        {
            DFS(i, vec);
        }

        if (ans == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

void DFS(int num, vector<vector<int>>& vec)
{

    visited[num] = true;

    for (int i = 0; i < vec[num].size(); i++)
    {
        if (visited[vec[num][i]]==false)
        {
            checked[vec[num][i]] = (checked[num] + 1) % 2;
            DFS(vec[num][i], vec);
        }
        else
        {
            if (checked[vec[num][i]] == checked[num])
            {
                ans = false;
            }
        }


    }

}