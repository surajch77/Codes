#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        vector<lld> v;
        lld temp;
        for(int i=0;i<n; ++i)
            cin >> temp, v.push_back(temp);
        vector<lld> dp(n,0);
        dp[0] = max((lld)0, v[0]);
        for(int i=1; i<=k; ++i)
            dp[i] = max(dp[i-1], v[i]);
        for(int i=k+1; i<n;++i)
            dp[i] = max(dp[i-1], dp[i-k-1] + v[i]);
        cout << dp[n-1] <<endl;
    }
}
