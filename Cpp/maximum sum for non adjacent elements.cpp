#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;++i)
        cin>>arr[i];
    int inc = arr[0],exc = 0,temp;
    for(int i = 1;i<n;++i){
        temp = inc;
        inc = max(inc,exc+arr[i]);
        exc = temp;
    }
    cout<<inc<<endl;
}
