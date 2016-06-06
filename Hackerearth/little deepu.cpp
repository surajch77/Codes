#include<bits/stdc++.h>
using namespace std;
#define llu unsigned int
int main(){
    int n;
    scanf("%d", &n);
    vector<llu> arr(n);
    for(int i=0; i<n; ++i){
        scanf("%u", &arr[i]);
    }
    int q;
    scanf("%d", &q);
    vector<llu> query(q);
    for(int i=0; i<q; ++i){
        scanf("%u", &query[i]);
    }
    for(int i=0; i<n; ++i)
        for(int j=0; j<q; ++j)
            if(arr[i] > query[j])
                arr[i]--;
    for(int i=0; i<n; ++i)
        printf("%u ", arr[i]);
}
