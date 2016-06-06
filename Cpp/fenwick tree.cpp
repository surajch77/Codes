/// #sh
#include<bits/stdc++.h>
#define LSone(s) (s & (-s))
#define lld long long int
using namespace std;

lld b1[1000007],b2[1000007];
int dp[1000007],ans[10000007],sum[10000007];
int n;
lld query(lld* ft, int b){
    lld sum = 0;
    for(; b; b-=LSone(b))
        sum+=ft[b];
    return sum;
}
lld query(int b){
    return query(b1, b) * b - query(b2, b);
}
lld range_query(int i, int j){
    return query(j) - query(i - 1);

}
void update(lld* ft, int k, lld val){
    for(; k<=n; k += LSone(k))
        ft[k] += val;
}
void range_update(int i, int j, int val){
    update(b1, i, val);
    update(b1, j+1, -val);
    update(b2, i, val*(i-1));
    update(b2, j+1, -val * j);
}
int main(){
        int m;
        scanf("%d%d",&n,&m);
        memset(b1,0,(n+1)*sizeof(lld));
        memset(b2,0,(n+1)*sizeof(lld));
        for(int i = 0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            range_update(a,b,1);
            for(int i = 0;i<=n;++i)
                cout<<b1[i]<<" ";
            cout<<endl;
            for(int i = 0;i<=n;++i)
                cout<<b2[i]<<" ";
            cout<<endl<<endl;
        }

        for(int i = 1;i<=n;++i)
            ans[i-1] = range_query(i,i),cout<<ans[i-1]<<" ";
        cout<<endl;
        int q;
        scanf("%d",&q);

        for(int i = 0;i<=1000006;++i)
            dp[ans[i]]++;
        for(int i = 1000005;i>=0;--i)
            sum[i] = sum[i+1] + dp[i];
        while(q--){
                int val;
                scanf("%d",&val);
                cout<<sum[val]<<"\n";
        }





}
