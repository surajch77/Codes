#include<bits/stdc++.h>
using namespace std;
#define lld long long
lld mod = 1000000007;
lld modpow(lld a, lld b){
    lld ans = 1;
    while(b){
        if(b&1)
            ans = ( a * ans ) % mod;
        a = ( a * a ) % mod;
        b /= 2;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<lld> v;
    lld temp;
    for(int i=0; i<n; ++i)
        scanf("%lld", &temp), v.push_back(temp);
    lld gcd = v[0];
    for(int i=1; i<n; ++i)
        gcd = __gcd(gcd, v[i]);
    lld pro = 1;
    for(int i=0; i<n; ++i)
        pro = ( pro * v[i] ) % mod;
    lld ans = modpow(pro, gcd);
    printf("%lld", ans);
}
