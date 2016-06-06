#include<bits/stdc++.h>
using namespace std;
bitset<10000017> bs; // for seive

#define lld long long int
void seive(uint32_t maxi){
    uint32_t val = 10007;
    bs.set();
    bs[0] = bs[1] = true;
    for(uint32_t i=2; i<=val; ++i)
        if(bs[i])
            for(uint32_t j=i*i; j<maxi; j+=i)
                bs[j] = false;

}
int main(){
    seive(10000007);
    uint32_t test;
    scanf("%I32d", &test);
    while(test--){
        uint32_t n;
        scanf("%I32d", &n);
        uint32_t sq = sqrt(n);
        if(bs[n] == true)
            printf("NO\n");
        else if(sq * sq == n and bs[sq] == true)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
