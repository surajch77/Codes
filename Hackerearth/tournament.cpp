
/// #sh

#include<bits/stdc++.h>

using namespace std;

map<string, int> m;

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; ++i){
        string s, t;
        cin >> s;
        cin >> t;
        m[s] += 1;
        m[t] += 1;
    }
    int mx = 0;
    set<string> st;
    for(auto it:m){
        if(it.second > mx)
            mx = it.second;
    }
    for(auto it:m){
        if(it.second == mx)
            st.insert(it.first);
    }
    cout << st.size() << endl;
    for(auto it:st)
        cout << it << endl;
}
