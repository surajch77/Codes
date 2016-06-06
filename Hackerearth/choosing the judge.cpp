/// #sh

#include<bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
        int test;
        scanf("%d", &test);
        int *arr;
        lld *dp;
        for(int t=1; t<=test; ++t){
            int n;
            scanf("%d", &n);
            arr = (int *)malloc((n+1) * sizeof(int));

            for(int i=1; i<=n; ++i)
                scanf("%d", &i[arr]);

            dp = (lld *)malloc((n+1)*sizeof(lld));
            memset(dp, 0, sizeof(dp));

            dp[0] = 0;
            dp[1] = arr[1];

            for(int i=2; i<=n; ++i)
                dp[i] = max(dp[i-1], dp[i-2] + (lld)arr[i]);


            printf("Case %d: ", t);
            cout << dp[n] << endl;


        }
    free(dp);
    free(arr);
}


