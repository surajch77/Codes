#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int ans = 0;
    for(int i=0; i<n; ++i){
        if(i+2>=n)
            break;
        ans = max(ans, arr[i+2]-arr[i]);
    }
    cout<<ans<<endl;
}
