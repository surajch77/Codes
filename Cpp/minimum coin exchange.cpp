#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int total,n;
    cin>>n>>total;
    int coins[n];
    for(int i = 1;i<=n;++i)
        cin>>coins[i];
    int dp[n+1][total+1];

    for(int i = 0;i<n+1;++i)
        dp[i][0] = 0;               //initialize the first column with zero
    for(int i = 1;i<=total;++i)
        dp[0][i] = 1000;        //initialize the first row with max to have no problem in i-1 part

    for(int i = 1;i<n+1;++i)
        for(int j = 1;j<=total;++j)
            if(j>=coins[i])
                dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i]]+1);
            else
                dp[i][j] = dp[i-1][j];
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=total;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}
