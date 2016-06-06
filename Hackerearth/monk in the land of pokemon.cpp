/// @da
#include<bits/stdc++.h>
using namespace std;
vector<int> values(1000006,0);
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        for(int i=0; i<1000005; ++i)
            values[i] = 0;
        scanf("%d", &n);
        int a, b;
        int cnt = 0;
        for(int i=1; i<=n; ++i){
            scanf("%d %d", &a, &b);
            if(a==b)
                continue;
            if(values[b])
                --values[b], ++values[a];
            else
                ++cnt, ++values[a];
            //cout<<cnt<<endl;
        }
        printf("%d\n", cnt);
    }
}
