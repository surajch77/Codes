/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        vector<bool> v(26, false);
        bool flag = true;

        int n;
        scanf("%d", &n);
        for(int i=0; i<n; ++i){
            string st;
            cin >> st;
            if(v[st[0] - 'a'])
                flag = false;
            else
                v[st[0] - 'a'] = true;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
