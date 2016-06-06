#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define all(c) c.begin(), c.end()
int main(){
    int n, q;
    cin >> n >> q;
    vector<lld> a, b;
    a.push_back(0);
    b.push_back(0);
    lld temp;
    for(int i=0; i<n; ++i)
        cin >> temp, a.push_back(temp);
    for(int i=0; i<n; ++i)
        cin >> temp, b.push_back(temp);
    for(int i=2; i<=n; i+=2)
        swap(a[i], b[i]);
    partial_sum(all(a), a.begin());
    partial_sum(all(b), b.begin());
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t==1)
                if(l%2)
                    printf("%lld\n", a[r] - a[l-1]);
                else
                    printf("%lld\n", b[r] - b[l-1]);

        else
            if(l%2==0)
                printf("%lld\n", a[r]-a[l-1]);
            else
                printf("%lld\n", b[r]-b[l-1]);
    }

}
