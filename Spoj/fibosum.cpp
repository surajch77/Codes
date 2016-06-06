#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;

const ll MOD = 1e9+7;
map<ll,ll> Fib;

ll fib(ll n)
{
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end())
      return Fib[n];
    Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % MOD;
    return Fib[n];
}

int main(){
	int test;
	scanf("%d",&test);
	for(int i=0; i<10; ++i)
        cout<<i<<" "<<fib(i)<<endl;
	while(test--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		ll first = fib(a)-1;
		ll second = fib(b+1)-1;
		ll ans = second - first;
		while(ans<0)
		    ans+=MOD;
		//cout<<first<<" "<<second<<endl;
		printf("%lld\n",ans);
	}
}

