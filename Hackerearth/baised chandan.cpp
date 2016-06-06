/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector<int> arr(n+1);
    int sum = 0;

    for(int i=0; i<n; ++i)
        scanf("%d", &arr[i]), sum += arr[i];

    int prev = arr[0];

    for(int i=1; i<n; ++i){
        if(arr[i])
            prev = arr[i];
        else
            sum -= prev, prev = 0;
    }

    cout << sum << endl;
}
