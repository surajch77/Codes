/// @da
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        vector<int> v;
        for(int i=0, temp; i<n; ++i)
            scanf("%d", &temp), v.push_back(temp);
        sort(v.rbegin(), v.rend());
        for(int i=0; i<n; ++i)
            printf("%d ", v[i]);
        printf("\n");

    }
}
