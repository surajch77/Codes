#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld etf(lld n){
	lld ans;
	ans=n;
	lld d=n;
	for(lld i=2;i*i<=n;++i){
		if(n%i==0) ans-=ans/i;
		while(n%i==0) n/=i;
	}
	if(n>1) ans-=ans/n;
	return ans;
}
int main(){
    int test;
    scanf("%d", &test);
    for(lld i=1; i<=20; i++)
        cout << i << " "<< etf(i)<<endl;
    while(test--){
        lld a, b;
        scanf("%lld %lld", &a, &b);
        //printf("%lld %lld\n", etf(a), etf(b));
        for(int i=a;i<=b;++i)
            cout<<etf(i)<<" ";
        cout<<endl;

    }
}
