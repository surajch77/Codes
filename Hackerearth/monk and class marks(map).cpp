#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int n;
    cin >> n;
    pair<int, string> m[n];
    string temp;
    int val;
    for(int i=0; i<n; ++i){
        cin >> temp >> val;
        m[i].first = -val;
        m[i].second = temp;
    }
    sort(m, m+n);
    //for(map<int, string>::iterator it=m.begin(); it!=m.end(); ++it)
      //  cout << it->second << (it->first * -1) << endl;
    for(int i=0; i<n; ++i)
        cout << m[i].second <<" "<< (m[i].first * -1) << endl;
}

