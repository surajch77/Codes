#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        set<string> s;
        string temp;
        for(int i=0; i<n; ++i){
            cin >> temp;
            s.insert(temp);
        }
        for(set<string>::iterator it=s.begin(); it!=s.end(); ++it)
            cout << *it <<"\n";

    }
}
