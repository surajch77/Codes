#include<bits/stdc++.h>
using namespace std;

#define mod 1988
#define maxn 5007
int ans[maxn][maxn];
int main(){
    ans[0][0] = ans[1][1] = 1;
    for(int i=2; i<maxn; ++i){
        for(int j=1;j<=i/2; ++j)
            ans[i][j] = (ans[i-1][j-1] + ans[i-j][j]) % mod;
        for(int j=i/2+1; j<=i; ++j)
            ans[i][j] = ans[i-1][j-1] % mod;
    }

    while(true){
        int n, k;
        scanf("%d %d", &n, &k);
        if(n==0 and k==0)
            break;
        printf("%d\n", ans[n][k]);
    }
}
