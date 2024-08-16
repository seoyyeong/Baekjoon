#include <string>
#include <vector>
#include <iostream>
#define INF 1'000'000'000

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arr[101][101];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j] = INF;
        }
    }
    
    for(int i=0;i<results.size();i++)
    {
        arr[results[i][0]][results[i][1]] = 1;
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
    
    bool bFlag;
    
    for(int i=1;i<=n;i++)
    {
        bFlag = true;
        for(int j=1;j<=n;j++)
        {  
            if(i!=j)
            {
                if(arr[i][j]==INF&&arr[j][i]==INF)
                {
                    bFlag=false;
                    break;
                }
            }

        }
        if(bFlag==true)
        {
            answer++;
        }
    }
    
    return answer;
}