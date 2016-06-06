/// @da
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld ones(lld val){
    int cnt = 0;
    while(val){
        cnt++;
        val = val&(val-1);
    }
    return cnt;
}
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        pair<lld, pair<int, lld> > pi[n];
        for(int i=0, temp; i<n; ++i){
            scanf("%lld", &temp);
            pi[i].first = ones(temp);
            pi[i].second.second = temp;
            pi[i].second.first = i;
        }

        sort(pi, pi+n);
        for(int i=0; i<n; ++i)
            printf("%lld ", pi[i].second.second);
        printf("\n");
    }
}
