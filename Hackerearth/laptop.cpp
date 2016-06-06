/// #sh

#include<bits/stdc++.h>

using namespace std;

map<string, int> m;

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        m[s] += 1;
    }
    int mx = 0;
    string ans;
    //cout << "done" << endl;
    for(auto it:m){
        if(it.second > mx)
            mx = it.second, ans = it.first;
    }

    cout << ans;
}
