/// #sh
#include<bits/stdc++.h>
#define lld long long int
#define mx 2000012
#define mod 1000000007
using namespace std;
lld fact[mx], invfact[mx];
lld ncr(lld n, lld r){
    return (((fact[n] * invfact[r]) % mod) * invfact[n-r] ) % mod;
}
int main(){
    int test;
    scanf("%d", &test);
    /// find the factorial and inverse factorial
    fact[0] = invfact[0] = invfact[1] = 1;
    for(int i=1; i<mx; ++i)
        fact[i] = (fact[i-1] * i ) % mod;
    for(int i=2; i<mx; ++i)
        invfact[i] = (mod - mod/i) * invfact[mod % i] % mod;
    for(int i=1; i<mx; ++i)
        invfact[i] = (invfact[i-1] * invfact[i]) % mod;
    while(test--){
        int n, k;
        scanf("%d %d", &n, &k);
        lld ans = ((2LL * ncr(n+k+1, k+2)) % mod - n + mod) % mod;
        printf("%lld\n", ans);
    }
}
