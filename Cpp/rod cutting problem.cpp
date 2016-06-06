#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,total;
    cin>>n>>total;
    int val[n+1],dp[n+1][total+1],len[n+1];
    for(int i = 1;i<=n;++i)
        scanf("%d",len+i);
    for(int i = 1;i<=n;++i)
        scanf("%d",val+i);

    for(int i = 0;i<total+1;++i)
        dp[0][i] = 0;
    for(int i = 0;i<n+1;++i)
        dp[i][0] = 0;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=total;++j)
            if(j>=len[i])
                dp[i][j] = max(dp[i-1][j],val[i]+dp[i][j-len[i]]);
            else
                dp[i][j] = dp[i-1][j];
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=total;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }



}
