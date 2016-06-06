/// #sh

#include<bits/stdc++.h>

using namespace std;

#define lld long long

int main(){
    int test;
    scanf("%d", &test);

    while(test--){
        int n;
        cin >> n;
        vector<pair<int, int> > v;

        for(int i=0; i<n; ++i){
            pair<int, int> temp;
            cin >> temp.first >> temp.second;

            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        vector<lld> dp(202, 0);

        dp[0] = v[0].second;
        lld ans = v[0].second;

        for(int i=1; i<n; ++i){
            dp[i] = v[i].second;

            for(int j=0; j<i; ++j){
                if(v[j].second < v[i].second and v[j].first < v[i].first)
                    dp[i] = max(dp[i], v[i].second + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}
