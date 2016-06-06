/// #sh

#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 3;
int b[maxn];
int dp[maxn][2];

int main(){
        int test;
        cin >> test;
        while(test--){
            memset(dp, 0, sizeof(dp));
            int n;
            cin >> n;
            for(int i=0; i<n; ++i)
                cin >> b[i];

            for(int i=1; i<n; ++i){
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + abs(b[i - 1] - 1));
                dp[i][1] = max(dp[i - 1][0] + abs(b[i] - 1), dp[i - 1][1]);
            }
            for(int i=0; i<n; ++i){
                for(int j=0; j<2; ++j)
                    cout << dp[i][j] << " ";
                cout << endl;
            }
            cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
        }
}
