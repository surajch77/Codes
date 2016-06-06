#include<bits/stdc++.h>
using namespace std;
#define lld long long
int main(){
    string s;
    cin >> s;
    set<long long > st;
    for(int i=0; i<s.size(); ++i){
            lld val = 0;
        for(int j=i;j<s.size(); ++j){
            val = val*173 + s[i];
            st.insert(val);
        }

    }

    cout << st.size();
}
