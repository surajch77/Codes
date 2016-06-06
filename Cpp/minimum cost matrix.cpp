#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter the size of matrix"<<endl;
    cin>>m>>n;
    int mat[m][n];
    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin>>mat[i][j];
    int dp[m][n];
    dp[0][0] = mat[0][0];
    for(int i = 1;i<n;++i)
        dp[0][i] = dp[0][i-1] + mat[0][i];
    for(int j = 1;j<m;++j)
        dp[j][0] = dp[j-1][0] + mat[j][0];
    for(int i = 1;i<m;++i)
        for(int j =1; j<n;++j)
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + mat[i][j];
    for(int i=0;i<m;++i){
         for(int j = 0 ;j<n;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }


    int ans = dp[m-1][n-1];
    cout<<ans<<endl;
}
