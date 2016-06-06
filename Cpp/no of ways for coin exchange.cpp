#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,total;
    cin>>total>>n;
    int coins[n+1];
    long int dp[n+1][total+1];
    for(int i = 1;i<n+1;++i)
        cin>>coins[i];
    for(int i = 0;i<n+1;++i)
        dp[i][0] = 1;
    for(int i = 0;i<total+1;++i)
        dp[0][i] = 0;
    for(int i = 1;i<n+1;++i)
        for(int j = 1;j<total+1;++j)
            if(j>=coins[i])
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
            else
                dp[i][j] = dp[i-1][j];
    for(int i = 0;i<n+1;++i){
        for(int j = 0;j<total+1;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }


}
