/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.size(); ++i)
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
            cout << (char)(s[i] - 32);
        else
            cout << s[i];

}
