#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> degree;
queue<int> q;
int n;
int m;

void tsort(void);

int main(void)
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    degree.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp;
        v.push_back(temp);
    }
    
    for(int i=0;i<m;i++)
    {
        int a;
        int b;
        
        cin>>a>>b;
        v[a].push_back(b);
        degree[b]++;
    }
    
    tsort();
    
    return 0;
}

void tsort(void)
{
    for(int i=1;i<=n;i++)
    {
        if(degree[i]==0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        
        cout<<temp<<' ';
        
        for(int i=0;i<v[temp].size();i++)
        {
            degree[v[temp][i]]--;
            if(degree[v[temp][i]]==0)
            {
                q.push(v[temp][i]);
            }
        }
    }
    
    
}