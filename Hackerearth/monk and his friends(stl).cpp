#include<bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        set<lld> s;
        lld temp;
        for(int i=0; i<n; ++i){
            scanf("%lld", &temp);
            s.insert(temp);
        }
        for(int i=0; i<m; ++i){
            scanf("%lld", &temp);
            if(s.find(temp)!=s.end())
                printf("YES\n");
            else
                printf("NO\n"), s.insert(temp);
        }
    }
}
