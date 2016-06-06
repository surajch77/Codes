#include<bits/stdc++.h>
using namespace std;

#define MAX 20004
int bit[MAX], ans[MAX], n;

void update(int i, int v){
    for(;i<=MAX; i+=(i & -i))
        bit[i] += v;
}

int query(int i){
    int ans = 0;
    for(;i>0; i-=(i & -i))
        ans += bit[i];
    return ans;
}

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        memset(bit, 0, sizeof bit);
        memset(ans, 0, sizeof ans);
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
            update(i, 1);
        int m=n, l=1, s, e;
        for(int i=1; i<=n; ++i){
            l = (l+i) % m;
            l = (!l) ? m : l;
            m--;
            s = 1; e = n;
            while(s<=e){
                int mid = (s+e)/2;
                if(query(mid) >= l) e = mid - 1;
                else if(query(mid) < l) s = mid + 1;
            }
            ans[s] = i;update(s, -1);
        }
        for(int i=1; i<=n; ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }
}
