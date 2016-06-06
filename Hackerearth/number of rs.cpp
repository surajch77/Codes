#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string str;
        cin >> str;
        vector<int> v;
        int cnt = 0;
        for(int i=0; i<str.size();++i)
            if(str[i] == 'R')
                v.push_back(-1), cnt++;
            else
                v.push_back(1);
        int sofar = 0, start = 0;
        for(int i=0; i<v.size(); ++i){
            start = max(v[i], start+v[i]);
            sofar = max(sofar, start);
        }
        cout << sofar + cnt<<endl;
    }
}
