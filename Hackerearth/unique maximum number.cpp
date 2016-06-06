/// #sh

#include<bits/stdc++.h>

using namespace std;

map<int, bool> m;

int ans = -1;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        int val;
        cin >> val;
        if(m.find(val) != m.end())
            m[val] = false;
        else
            m[val] = true;
    }
    int mx = -1;
    for(auto it:m){
        if(it.second == true)
            mx = max(mx, it.first);
    }

    cout << mx;
}
