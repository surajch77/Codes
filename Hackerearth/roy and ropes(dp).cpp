#include <bits/stdc++.h>
using namespace std;

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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int test;
    sc1(test);
    while(test--){
        int n, temp;
        sc1(n);
        vi low, high;
        for(int i=0; i<n-1; ++i)
            sc1(temp), low.pb(temp);
        for(int i=0; i<n-1; ++i)
            sc1(temp), high.pb(temp);
        int ans = n;
        for(int i=0; i<n-1; ++i)
            ans = max(ans, i+1+max(low[i], high[i]));
        pr1(ans);
    }

}

