/// @da
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int  n, x;
        scanf("%d %d", &n, &x);
        vector<int> v;
        for(int i=0, temp; i<n; ++i)
            scanf("%d", &temp), v.push_back(temp);
        bool found = false;
        int sum = v[0];
        int start = 0;
        for(int i=1; i<n; ++i){
            while(sum > x){
                sum -= v[start];
                start++;
            }
            if(sum == x)
                found = true;
            sum += v[i];
        }
        while(sum > x){
                sum -= v[start];
                start++;
            }
            if(sum == x)
                found = true;

        if(found)
            printf("YES\n");
        else
            printf("NO\n");

    }
}
