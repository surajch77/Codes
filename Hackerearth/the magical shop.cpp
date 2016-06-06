#include<bits/stdc++.h>
using namespace std;

int main(){
    uint64_t a, b;
    cin >> a >> b;
    string str;
    cin >> str;
    uint64_t ans = 0;
    for(int i=0; i<str.size(); ++i){
        if(str[i] == '1')
            ans = (ans + a) % b;
        a = (a * a) % b;
    }
    cout << ans << endl;
}
