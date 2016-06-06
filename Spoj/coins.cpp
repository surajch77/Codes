#include<bits/stdc++.h>
using namespace std;
#define lld long long
map<lld, lld> m;
lld req(lld n){
    if(n==0)
        return 0;
    lld a = n/2, b = n/3, c = n/4;
    if(m.find(n)==m.end()){
        m[n] = max(n, req(a) + req(b) + req(c));
        return m[n];
    }

    else
        return m[n];
}
int main(){
    lld n;
    while(scanf("%lld", &n) > 0){
        lld ans = req(n);
        printf("%lld\n", ans);
    }
}
