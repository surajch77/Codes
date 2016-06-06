#include<stdio.h>
#define llu unsigned long long
int main(){
    int n, i, j, q;
    scanf("%d", &n);
    llu arr[n];
    for(i=0; i<n; ++i)
        scanf("%llu", &arr[i]);
    scanf("%d", &q);
    llu query[q];
    for(i=0; i<q; ++i)
        scanf("%llu", &query[i]);
    for(i=0; i<n; ++i){
        for(j=0; j<q; ++j)
            if(arr[i] > query[j])
                arr[i]--;
        printf("%llu ", arr[i]);
    }



}
