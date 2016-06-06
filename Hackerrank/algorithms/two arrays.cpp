/// #sh

#include<bits/stdc++.h>

using namespace std;
#define u_int uint32_t
int main(){

    int test;
    cin >> test;
    while(test--){
        int n;
        u_int k;
        cin >> n >> k;

        vector<u_int> a(n, 0), b(n, 0);
        for(int i=0; i<n; ++i)
            cin >> a[i];

        for(int i=0; i<n; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        bool flag = true;
        for(int i=0; i<n; ++i)
            if(a[i] + b[i] < k)
                flag = false;

        if(flag)
            puts("YES");
        else
            puts("NO");

    }
}
