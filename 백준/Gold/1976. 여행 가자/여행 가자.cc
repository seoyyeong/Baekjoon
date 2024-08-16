#include <iostream>
#include <vector>

using namespace std;

int arr[200][200];
bool visited[200];
int n;
int m;
vector<int> v;

void DFS(int num);


int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        arr[i][i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    DFS(v[0] - 1);

    for (int i = 0; i < v.size(); i++)
    {
        if (visited[v[i] - 1] == false)
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';

    return 0;
}

void DFS(int num)
{
    if (visited[num] == true)
    {
        return;
    }

    visited[num] = true;

    for (int i = 0; i < n; i++)
    {
        if (arr[num][i] == 1)
        {
            DFS(i);
        }
    }


}