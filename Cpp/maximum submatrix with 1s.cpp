#include<bits/stdc++.h>
using namespace std;
char arr[1002][1002];
int dp[1002][1002];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int l, r, q;
    scanf("%d %d %d", &l, &r, &q);
    //cout<<l<<" "<<r<<endl;
    for(int i=0; i<l; ++i)
        gets(arr[i]);
    //for(int i=0; i<l; ++i)
        //puts(arr[i]);
    bool M[10002];
    for(int i=1; i<l+2; ++i)
            for(int j=1; j<r+2; ++j){
                if(arr[i-1][j-1] == 'M'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    M[dp[i][j]] = true;
                }
                else
                    dp[i][j] = 0;

        }
    for(int i=0; i<l+2; ++i){
            for(int j=0; j<r+2; ++j)
                cout<<dp[i][j]<<" ";
            cout<<endl;
    }
    for(int i=0; i<l+1; ++i)
            for(int j=0; j<r+1; ++j)
                dp[i][j] = 0;
        bool F[10002];
    for(int i=1; i<l+2; ++i)
            for(int j=1; j<r+2; ++j){
                if(arr[i-1][j-1] == 'F'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    F[dp[i][j]] = true;
                }
                else
                    dp[i][j] = 0;

        }
    for(int i=0; i<l+2; ++i){
            for(int j=0; j<r+2; ++j)
                cout<<dp[i][j]<<" ";
            cout<<endl;
    }
    while(q--){
        char x;
        int val, chk;
        bool flag = false;
        scanf("%d %c", &val, &x);
        if(x == 'M')
            flag = M[val];
        else
            flag = F[val];
        /*
        for(int i=0; i<l+2; ++i){
            for(int j=0; j<r+2; ++j)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        */
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
}
