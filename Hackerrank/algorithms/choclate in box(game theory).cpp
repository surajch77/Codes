/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];

    int val  = 0;
    for(int i=0; i<n; ++i)
        cin >> arr[i], val ^= arr[i];

    int cnt = 0;
    for(int i=0; i<n; ++i)
        if((val ^ arr[i]) < arr[i])
                cnt++;
    cout << cnt << endl;
}
