#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        string s;
        cin >> s;
        string str = "";
        str+=s[0];
        for(int i=1; i<s.size(); ++i)
            if(s[i]!=s[i-1])
                str+=s[i];
        string str1 = str;
        reverse(str.begin(), str.end());
        if(str == str1)
            puts("YES");
        else
            puts("NO");
    }
}
