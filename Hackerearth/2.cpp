#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    pair<int, int> pi[n];
    for(int i=0; i<n; ++i)
        scanf("%d %d", &pi[i].first, &pi[i].second);
    sort(pi, pi+n);
    lld ans[n+1];
    ans[0] = 0;
    for(int i=0;i<n;++i)
        ans[i+1] = pi[i].second  + ans[i];
    vector<int> pie;
    for(int i=0;i<n;++i)
        pie.push_back(pi[i].first);
    lld mx = 0;

    for(int i=0;i<n;++i){
        int it = upper_bound(pie.begin()+i, pie.end(), pie[i] + d-1) - pie.begin();
        lld diff = ans[it] - ans[i];
        mx = max(diff, mx);

    }
    printf("%I64d", mx);

}
