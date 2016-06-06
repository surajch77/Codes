#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
bitset<100000017> bs; // for seive
#define lld long long int
vector<int> primes;
void show(vector<int> &v){
    for(int i=0; i<10; ++i)
        cout<<v[i]<<" ";
    cout<<endl;
}
void seive(int maxi){
    int val = maxi;
    int sq = sqrt(maxi);
    bs.set();
    bs[0] = bs[1] = false;
    for(int i=2; i<=sq; ++i)
        if(bs[i]){
                //cout<<i<<endl;
                primes.push_back(i);
            for(int j=2; j*i<maxi; j++)
                bs[j*i] = false;
        }
    for(int i=sq+1;i<maxi;++i)
        if(bs[i])
            primes.push_back(i);
}
int main(){
    seive(1000000);
    vector<int> v;
    v.push_back(0);
    for(int i=0; i<1000000; ++i)
        if(bs[i])
            v.push_back(v.back()+1);
        else
            v.push_back(v.back());
    //show(v);
    int test;
    scanf("%d", &test);
    vector<int> ans(44,0);
    ans[0] = ans[1] = ans[2] = ans[3] = 1;
    for(int i=4; i<44;++i)
        ans[i] = ans[i-1] + ans[i-4];
    while(test--){
        int n;
        scanf("%d", &n);
        cout << v[ans[n]+1]<<endl;
    }
}
