#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1; i<=n;++i)
        cin>>arr[i];
    int dp[n+1][n+1][3];
    for(int i = 1;i<=n;++i)
        for(int j =1 ;j<=n;++j)
            dp[i][j][1] = 0,dp[i][j][2] = 0;

    for(int i = 1;i<=n;++i)
            dp[i][i][1] = arr[i], dp[i][i][2] = 0;
    for(int i = n-1;i>=1;i--)
        for(int j = i+1;j<=n;++j){
            if(dp[i+1][j][2]+arr[i]>dp[i][j-1][2]+arr[j])
                dp[i][j][1] = dp[i+1][j][2] + arr[i],dp[i][j][2] = dp[i+1][j][1];
            else
                dp[i][j][1] = dp[i][j-1][2] + arr[j],dp[i][j][2] = dp[i][j-1][1];

        }



    for(int i=1;i<=n;++i){
        for(int j=1 ;j<=n;++j)
            printf("(%d,%d)  ",dp[i][j][1],dp[i][j][2]);
        cout<<endl;
    }





}
