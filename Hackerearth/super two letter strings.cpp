/// #sh

#include<bits/stdc++.h>

using namespace std;

#define lld long long

const int mod = 1e9 + 7;

int main(){
    lld dp[10003];

    int test;
    cin >> test;

    while(test--){
        int n, k;
        cin >> n >> k;

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i=1; i<=n; ++i){
            for(int j=i-1; j>=0 and i-j<=k; --j)
                dp[i] = (dp[i] + dp[j]) % mod;
        }
        cout << dp[n] << endl;
    }
}


