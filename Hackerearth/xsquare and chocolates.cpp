/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){

    int test;
    scanf("%d", &test);
    while(test--){
        string str;
        cin >> str;

        vector<int> dp(str.size()+1, 0);

        bool same = str[0] == str[1];
        int maxi = 0;

        for(int i=2; i<str.size(); ++i){
            if(same and str[i] == str[i-1])
                continue;
            else
                dp[i] = 3 + ((i-3>=0)?dp[i-3]:0);

            same = str[i]==str[i-1];
            maxi = max(maxi, dp[i]);
        }
        cout << str.size() - maxi << endl;
    }

}
