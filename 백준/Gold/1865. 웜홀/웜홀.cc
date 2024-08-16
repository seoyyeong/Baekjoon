#include <iostream>
#include <tuple>
#include <vector>
#include <climits>

using namespace std;

#define INF 50'000'0000

typedef tuple<int, int, int> t;
vector<int> dist;
vector<t> v;

int main(void)
{
    int n;
    int m;
    int w;
    int tc;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int s;
        int e;
        int t;
        bool bCheck;

        cin >> n >> m >> w;

        dist.resize(n + 1);
        v.clear();

        for (int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            v.push_back(make_tuple(s, e, t));
            v.push_back(make_tuple(e, s, t));
        }

        for (int j = 0; j < w; j++)
        {
            cin >> s >> e >> t;
            v.push_back(make_tuple(s, e, -t));
        }
        //start
        bCheck = false;

        fill(dist.begin(), dist.end(), INF);
        dist[1] = 0;
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < v.size(); k++)
            {
                int start = get<0>(v[k]);
                int end = get<1>(v[k]);
                int time = get<2>(v[k]);

                if (dist[end] > dist[start] + time)
                {
                    dist[end] = dist[start] + time;
                }
            }
        }

        for (int j = 0; j < v.size(); j++)
        {
            int start = get<0>(v[j]);
            int end = get<1>(v[j]);
            int time = get<2>(v[j]);

            if (dist[end] > dist[start] + time)
            {
                bCheck = true;
            }

        }

        if (bCheck == true)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}