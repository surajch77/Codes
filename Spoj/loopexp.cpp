#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    double ans[100006];
    ans[1] = 1;
    for(int i=2; i<100006; ++i)
        ans[i] = ans[i-1] + 1.0/i;
    while(test--){
        int n;
        scanf("%d", &n);
        printf("%.14lf\n", ans[n]);
    }
}
