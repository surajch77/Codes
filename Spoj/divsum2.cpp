#include<bits/stdc++.h>
using namespace std;
bitset<100000017> bs; // for seive
#define lld long long int
vector<int> primes;
void seive(int maxi){
    int val = maxi;
    bs.set();
    bs[0] = bs[1] = false;
    for(int i=2; i<10007; ++i)
        if(bs[i]){
                //cout<<i<<endl;
                primes.push_back(i);
            for(int j=1; j*i<maxi; j++)
                bs[j*i] = false;
        }
    for(int i=10007;i<maxi;++i)
        if(bs[i])
            primes.push_back(i);


}
int main(){
    seive(100000008);
    cout<<"done"<<primes.size()<<endl;
    primes.
    int test;
    scanf("%d", &test);
    while(test--){
        lld n;
        scanf("%lld", &n);
        lld sum = 1;
        lld temp = n;
        int sq = sqrt(n);
        for(int i=0; i<primes.size(); ++i){
            if(primes[i] > sq)
                break;
            int cnt = 0;
            if(n%primes[i] == 0){

                while(n%primes[i]==0){
                n/=primes[i];
                cnt++;
            }
            //cout<<primes[i]<<" " <<cnt<<endl;
            sum *= (pow(primes[i], cnt+1) - 1)/(primes[i]-1);
            }

            if(n==1)
                break;
            sq = sqrt(n);
        }

        if(n!=1)
            sum *= (n+1);
        printf("%lld\n", sum-temp);
    }
}
