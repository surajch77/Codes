/// #sh

#include<bits/stdc++.h>
#define lld long long int
using namespace std;

const int mod = 1e9 + 7;
string num;

int main(){

    cin >> num;
    lld val = num[0] - '0';
    int n = (int)num.size();
    lld ans = num[0] - '0';
    for(int i=1; i<n; ++i){
        int dig = num[i] -'0';
        val = ((lld)dig * (i+1) + 10*val) % mod;
        ans = (ans + val) % mod;
    }
    cout << ans << endl;
}
