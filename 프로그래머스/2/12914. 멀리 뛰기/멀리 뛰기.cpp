#include <string>
#include <vector>
#include <iostream>

using namespace std;


int dp[2][2000];
    
long long solution(int n) {
    long long answer = 0;
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[0][1] = 1;
    dp[1][1] = 1;
    
    for(int i=2;i<n;i++)
    {
        dp[0][i] =(dp[0][i-1] + dp[1][i-1])%1234567;
        dp[1][i] =(dp[0][i-2] + dp[1][i-2])%1234567;
        //cout<<i <<" : "<<dp[0][i]<<' '<<dp[1][i]<<'\n';
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<i <<" : "<<dp[0][i]<<' '<<dp[1][i]<<'\n';
        
    }

    
    answer = (dp[0][n-1] + dp[1][n-1]) % 1234567;
    return answer;
}