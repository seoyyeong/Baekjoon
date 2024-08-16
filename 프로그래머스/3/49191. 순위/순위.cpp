#include <string>
#include <vector>
#include <queue>

using namespace std;

int tsort(int n, vector<vector<int>>& list);

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> list;

    list.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        vector<int> temp;
        list.push_back(temp);
    }

    for (int i = 0; i < results.size(); i++)
    {
        list[results[i][0]].push_back(results[i][1]);
    }

    answer = tsort(n, list);

    return answer;
}

int tsort(int n, vector<vector<int>>& list)
{
    vector<int> degree;
    queue<int> q;
    vector<int> ans;
    //int ans = 0;

    degree.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        degree[i] = list[i].size();
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for (int i = 0; i < list[temp].size(); i++)
        {
            degree[list[temp][i]]--;
            if (degree[list[temp][i]] == 0)
            {
                q.push(list[temp][i]);
            }
        }
    }

    return ans.size();
}