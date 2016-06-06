#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;++i)
        cin>>arr[i];
    int dp[n];
    dp[0] = 0;

    for(int i = 1;i<n;++i)
        for(int j = 0;j<n;++j)
            if(i<=j+arr[j])
                dp[i] = min(dp[i],dp[j]+1);
    for(int i = 0;i<n;++i)
        cout<<dp[i]<<" ";

}
