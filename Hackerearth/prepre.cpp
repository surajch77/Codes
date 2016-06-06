#include<bits/stdc++.h>
using namespace std;
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    string s, t;
    cin >> s;
    cin >> t;
    int j = 0;
    for(int i=0; i<t.size(); ++i){
        if(j==s.size()-1)
            break;
        if(t[i]==s[j])
            ++j;
    }
    cout << j <<endl;
}

