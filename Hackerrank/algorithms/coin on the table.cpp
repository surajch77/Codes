/// #sh

#include<bits/stdc++.h>

using namespace std;

char arr[52][52];
int dp[52][52][1001];
int n, m, k;

void solve(int r, int c, int t, int val){
    if(r < 0 or r >= n or c < 0 or c >= m or t > k)
        return;
    if(val < dp[r][c][t] or dp[r][c][t] == -1){
        dp[r][c][t] = val;
        if(arr[r][c] != '*'){
            solve(r, c+1, t+1, val + (arr[r][c] != 'R'));
            solve(r, c-1, t+1, val + (arr[r][c] != 'L'));
            solve(r+1, c, t+1, val + (arr[r][c] != 'D'));
            solve(r-1, c, t+1, val + (arr[r][c] != 'U'));
        }
        else
            solve(r, c, t+1, val);
    }
}
int main(){

    cin >> n >> m >> k;
    int r, c;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == '*')
                r = i, c = j;
        }
    }



    memset(dp, -1, sizeof(dp));
    solve(0, 0, 0, 0);
    cout << dp[r][c][k] << endl;
}
