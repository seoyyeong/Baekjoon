#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    int dist = n;
    int x = 0;
    int y = -1;
    int num = 0;
    int max = 0;
    bool con = true;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        temp.resize(i + 1);
        v.push_back(temp);
        max += i + 1;
    }


        while (1)
        {

            for (int i = 0; i < dist; i++)
            {

                v[++y][x] = ++num;
            }

            if(dist-- < 0)
            {
                break;   
            }
            for (int i = 0; i < dist; i++)
            {

                v[y][++x] = ++num;
            }
            if(dist-- < 0)
            {
                break;   
            }
            for (int i = 0; i < dist; i++)
            {
                v[--y][--x] = ++num;
            }
            if(dist-- < 0)
            {
                break;   
            }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}