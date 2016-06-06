#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        vector<int> v;
        int n, temp;
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", &temp), v.push_back(temp);
        vector<int> sum;
        sum.push_back(0);
        for(int i=0; i<n; ++i)
            sum.push_back(sum.back() + v[i]);
        bool flag = false;
        for(int i=1; i<=n; ++i){
            if(sum[i-1] == sum[n] - sum[i])
                flag = true;
        }

        if(flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
