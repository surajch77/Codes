#include<bits/stdc++.h>
using namespace std;
bool dp[107][100007];    /// n * sum
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        int arr[n+1];
        int msum = 0;
        for(int i=1; i<=n; ++i)
            scanf("%d", arr + i), msum += arr[i];

        for(int i=0; i<=n; ++i)
            dp[i][0] = true;

        for(int j=1; j<=msum; ++j)
            dp[0][j] = false;

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=msum; ++j)
                if(j-arr[i] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i]];
        int result = 0;
        for(int j=1; j<=msum; ++j)
            if(dp[n][j])
                result += j;
        printf("%d\n", result);
        multiset<int> m;

    }
}
