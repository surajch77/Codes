#include<bits/stdc++.h>
using namespace std;
#define lld long long int

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        lld temp;
        vector<lld> arr, sum(n+1, 0), dp(n+1,0);
        arr.push_back(0);
        for(int i=0; i<n; ++i)
            cin >> temp, arr.push_back(temp);
        reverse(arr.begin()+1, arr.end());
        partial_sum(arr.begin(), arr.end(), sum.begin());
        dp[0] = 0;
        dp[1] = arr[1];
        dp[2] = dp[1]+arr[2];
        dp[3] = dp[2]+arr[3];
        for(int i=4; i<=n; ++i){
            dp[i] = max((lld)-1, sum[i-1]-dp[i-1]+arr[i]);
            dp[i] = max(dp[i], sum[i-2]-dp[i-2]+arr[i]+arr[i-1]);
            dp[i] = max(dp[i], sum[i-3]-dp[i-3]+arr[i]+arr[i-1]+arr[i-2]);
        }
        cout<<dp[n]<<endl;
    }
}
/*
long long sum = 0;
        dp[n] = dp[n + 1] = dp[n + 2] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
              sum += a[i];
              dp[i] = sum - min(min(dp[i + 1], dp[i + 2]), dp[i + 3]);
         }
        printf("%lld\n",dp[0]);
*/
