#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        n++;
        m++;

        int dp[n][m],arr[n][m];
        for(int i = 1;i<n;++i)
            for(int j = 1;j<m;++j)
                cin>>arr[i][j],dp[i][j] = -1;

        dp[1][1] = 1;
        for(int i = 2;i<n;++i)
            if(dp[i-1][1] != -1)
                if(arr[i][1]>arr[i-1][1])
                    dp[i][1]=dp[i-1][1]+1;
                else
                    dp[i][1]=-1;

        for(int i = 2;i<m;++i)
            if(dp[1][i-1] != -1)
                if(arr[1][i]>arr[1][i-1])
                    dp[1][i]=dp[1][i-1]+1;
                else
                    dp[1][i]=-1;

        for(int i = 2;i<n;++i){
            for(int j =2;j<m;++j){
                if(dp[i-1][j]==-1 && dp[i][j-1]==-1)
		    dp[i][j]=-1;
		else if(dp[i-1][j]!=-1 && dp[i][j-1]==-1)
		{
		    if(arr[i-1][j]<arr[i][j])dp[i][j]=dp[i-1][j]+1;
		    else dp[i][j]=-1;
		}
		else if(dp[i-1][j]==-1 && dp[i][j-1]!=-1)
		{
		    if(arr[i][j-1]<arr[i][j])dp[i][j]=dp[i][j-1]+1;
		    else dp[i][j]=-1;
		}
		else
		{
		    if(arr[i][j-1]<arr[i][j])dp[i][j]=dp[i][j-1]+1;
		    else dp[i][j]=-1;
		    if(arr[i-1][j]<arr[i][j])dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
		}
            }

        }

             for(int i = 1;i<n;++i){
                for(int j = 1;j<m;++j)
                    cout<<dp[i][j]<<" ";
                cout<<endl;
            }
            int ans = 1;
            for(int i = 1;i<n;++i)
                for(int j = 1;j<m;++j)
                    ans = max(ans,dp[i][j]);
            cout<<ans<<endl;
    }

}
