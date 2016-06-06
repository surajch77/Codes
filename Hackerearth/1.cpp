#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n, k;
        scanf("%d%d", &n, &k);
        int temp;
        while(n--){
            scanf("%d", &temp);
            if(temp<=0)
                k--;
        }
        if(k<=0)
            printf("NO\n");
        else
            printf("YES\n");


    }
}
