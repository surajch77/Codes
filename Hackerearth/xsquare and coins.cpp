/// #sh

#include<bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
    int test;
    scanf("%d", &test);

    while(test--){
        int n, k;
        scanf("%d %d", &n, &k);

        //int *arr = (int *)malloc((n+1)*sizeof(int));

        lld *arr = new lld[n+1];

        for(int i=0; i<n; ++i)
            scanf("%d", &i[arr]);

        lld ans = 0;

        lld cur = 0;

        for(int i=0; i<n; ++i){
            if(arr[i] <=k )
                cur += arr[i], ans = max(ans, cur);
            else{
                cur = 0;
            }
        }
        cout << ans << endl;
        delete [] arr;
    }
}
