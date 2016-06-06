/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n+1];
    int index[n+1];

    for(int i=0; i<n; ++i){
        cin >> arr[i];
        index[arr[i]] = i;
    }

    for(int i=0; i<n and k > 0; ++i){
        if(arr[i] == n-i)
            continue;
        arr[index[n-i]] = arr[i];
        index[arr[i]] = index[n-i];
        arr[i] = n-i;
        index[n-i] = i;
        k--;
    }
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
}
