#include<bits/stdc++.h>
#define lld long long int
using namespace std;
map<int,lld> m;
lld ans(lld val){
    if(val==0)
        return 0;
    else if(m.count(val))
        return m[val];
    else
        return m[val] = max(val, ans(val/2) + ans(val/4) + ans(val/3));
}
int main(){
    lld n;
    while(scanf("%lld", &n) > 0){
        lld val = ans(n);
        printf("%lld\n", val);
    }
}
