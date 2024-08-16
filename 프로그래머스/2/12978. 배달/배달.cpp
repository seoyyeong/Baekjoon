#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> P;


int solution(int N, vector<vector<int> > road, int K) {
    
    int answer = 0;
    vector<int> dist(N+1, INT_MAX);
    vector<bool> checked(N+1, false);
    vector<vector<P>> v(N+1);
    priority_queue<P, vector<P>, greater<P>> pq;
    
    for(int i=0;i<road.size();i++)
    {
        v[road[i][0]].push_back({road[i][2], road[i][1]});
        v[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    
    dist[1] = 0;
    pq.push({0,1});
    
    while(!pq.empty())
    {
        int idx;
        idx = pq.top().second;
        pq.pop();
        
        if(checked[idx]==true)
        {
            continue;
        }
        checked[idx] = true;
        
        for(int i=0;i<v[idx].size();i++)
        {
            int next = v[idx][i].second;
            int d    = v[idx][i].first;
            if(dist[next]>dist[idx]+d)
            {
                dist[next] = dist[idx]+d;
                pq.push({dist[next],next});
            }
        }
        
    }
    
    
    for(int i=1;i<=N;i++)
    {
        if(dist[i]<=K)
        {
            answer++;
        }
    }
    return answer;
}