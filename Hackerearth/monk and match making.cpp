#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld h1[100007], h2[100007];
lld p1[100007], p2[100007];
int main(){
    string s;
    int b1 = 44;
    int b2 = 167;
    int m1 = 10000009;
    int m2 = 10000007;
    cin >> s;
    int n = s.size();

    p1[0] = p2[0] = 1;

    for(int i=1; i<=n; ++i){
        p1[i] = (b1 * p1[i-1]) % m1;
        p2[i] = (b2 * p2[i-1]) % m2;
    }
    h1[0] = h2[0] = 0;
    for(int i=1; i<=n; ++i){
        h1[i] = (b1 * h1[i-1] + (s[i-1] - 'a') + 1) % m1;
        h2[i] = (b2 * h2[i-1] + (s[i-1] - 'a') + 1) % m2;
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int l1, l2, r1, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(r1-l1 == r2-l2){
            int len = r1-l1+1;
            lld res1 = (h1[r1] - (h1[l1-1]*p1[len])%m1 + m1) % m1;
            lld res2 = (h2[r1] - (h2[l1-1]*p2[len])%m2 + m2) % m2;
            lld res3 = (h1[r2] - (h1[l2-1]*p1[len])%m1 + m1) % m1;
            lld res4 = (h2[r2] - (h2[l2-1]*p2[len])%m2 + m2) % m2;
            if(res1 == res3 and res2 == res4)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
    }
}
