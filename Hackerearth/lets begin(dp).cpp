
#include <bits/stdc++.h>
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d %d",&x,&y)
#define sc3(x,y,z) scanf("%d %d %d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld %lld",&x,&y)
#define scll3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define show(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)
#define maxn 1000007
vi dp(maxn, 1000000000);
int pr[]  = {2, 3, 5, 7};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    dp[2] = 1;
    dp[3] = 1;
    dp[5] = 1;
    dp[7] = 1;
    for(int i=0; i<maxn; ++i)
        for(int j=0; j<4; ++j)
            if(i-pr[j] > 0)
                dp[i] = min(dp[i], dp[i-pr[j]] + 1);
    for(int i=0; i<maxn; ++i)
        if(dp[i]>=1000000000)
            dp[i] = -1;
    int test;
    sc1(test);
    while(test--){
        int x;
        sc1(x);
        cout << dp[x] <<endl;
    }

}
