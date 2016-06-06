#include<bits/stdc++.h>
using namespace std;
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

vector<long long int> arr(100005,0);
vector< vector<int> > monkeys(100005,vector<int> (1,0));
vector<bool> bs(100006, false);
long long int  recurse(int i){
    long long int sum = arr[i];
    bs[i] = true;
    for(int j=0; j<monkeys[i].size(); ++j)
        if(bs[monkeys[i][j]] == 0)
            sum += recurse(monkeys[i][j]);
    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE
        f_in("inp.txt");
        f_out("out.txt");
    #endif // ONLINE_JUDGE

    //ios_base::sync_with_stdio(false);
    int test;
    scanf("%d", &test);
    while(test--){

        int n, m, a, b;
        long long int temp;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n+2;++i){
            bs[i] = false;
            monkeys[i].clear();
        }
        for(int i=0; i<m; ++i){
            scanf("%d %d", &a, &b);
            monkeys[a].push_back(b);
            monkeys[b].push_back(a);
        }

        arr[0] = 0;
        for(int i=0; i<n; ++i){
            scanf("%lld", &temp);
            arr[i+1] = temp;
        }
        long long int ans = 0;
        for(int i=1; i<=n; ++i){
            if(bs[i] == 0){
                long long int val = recurse(i);
                ans = max(ans, val);
            }

        }
        printf("%lld\n", ans);
    }
}
