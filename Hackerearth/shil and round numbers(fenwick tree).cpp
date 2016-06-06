#include<bits/stdc++.h>
using namespace std;
#define lld long long
int n, q;
int bit[200007];
int round(lld x){
    if(x < 0)
        return 0;
    if(x == 0)
        return 0;
    int last = x % 10;
    while(x>9)
        x /= 10;
    return x==last;

}
void update(int id, int val){
    for(;id<=n; id += id&(-id))
        bit[id] += val;
}
int query(int id){
    int ans = 0;
    for(; id>0; id -= id&(-id))
            ans += bit[id];
    return ans;
}
vector<lld> v;
int main(){
    scanf("%d %d", &n, &q);
    lld temp;
    v.push_back(0);
    for(int i=0; i<n; ++i){
            scanf("%lld", &temp);
            update(i+1, round(temp));
            v.push_back(temp);
    }
    while(q--){
        lld t, l, r;
        scanf("%lld %lld %lld", &t, &l, &r);
        if(t == 2){
            update(l, -round(v[l]));
            v[l] = r;
            update(l, round(v[l]));
        }
        else
            printf("%d\n", query(r) - query(l-1));;
    }


}
