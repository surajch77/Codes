/// #sh

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;

int arr[maxn];
int main(){
    int test;

    scanf("%d", &test);
    while(test--){
        memset(arr, 0, sizeof(arr));
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; ++i){
            int temp;
            scanf("%d", &temp);
            arr[temp]++;
        }
        int maxi = 0;
        for(int i=0; i<maxn; ++i)
            if(arr[i] > maxi)
                maxi = arr[i];
        for(int i=maxn; i>=0; --i)
            if(arr[i] == maxi)
                printf("%d ", i);
        puts("");
    }
}
