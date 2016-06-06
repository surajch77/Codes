#include<bits/stdc++.h>
using namespace std;
bitset<10000007> bs;
int bs_1[10000007];
vector<int> primes;
#define lld long long int
void seive(int maxi){
    for(int i=0; i<=maxi; ++i)
        bs_1[i] = 1;
    int sq = sqrt(maxi);
    bs.set();
    bs[0] = bs[1] = false;
    bs_1[0] = 0;bs_1[1] = 1;
    primes.push_back(2);

    //for(int i=4; i<=maxi; i+=2)
        //bs[i] = false, bs_1[i] = 2 ;

    for(int i=2; i<=sq; i++)
        if(bs[i]){
            primes.push_back(i);
            for(int j=i*i; j<=maxi; j+=i){
                bs[j] = false;
                if(bs_1[j]==1)
                    bs_1[j] = i;
            }


        }

    //for(int i=sq+1; i<maxi; ++i)
        //if(bs[i])
           // primes.push_back(i);

}
int main(){
    seive(10000006);
    int n;

    while(scanf("%d", &n)!=EOF){
        if(n==1){
            printf("1");
        }
        else{
        printf("1");
        while(n%2==0)
            printf(" x 2"), n/=2;
        while(n){
            if(bs_1[n]!=1 && n!=1){
					printf(" x %d",bs_1[n]);
					n/=bs_1[n];
				}
			else{
					if(n==1) break;
                        printf(" x %d",n);
					break;
				}
        }

        }

         printf("\n");
    }

}
