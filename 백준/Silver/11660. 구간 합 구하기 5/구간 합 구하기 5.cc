#include <iostream>
#define dfARR_MAX 1025

using namespace std;

int arr[dfARR_MAX][dfARR_MAX];

int main(void)
{
    int n;
    int m;
    int x1;
    int y1;
    int x2;
    int y2;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            arr[i][j]+=(arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]);
        }
    }
        
    for(int i=0;i<m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]<<'\n';
    }
    
    return 0;
}