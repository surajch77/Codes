#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int len1 = str1.size();
    int len2 = str2.size();
    len1++;
    len2++;
    int dp[len2][len1];

    for(int i = 0;i<len1;++i)
        dp[0][i] = i;
    for(int i = 0;i<len2;++i)
        dp[i][0] = i;
    for(int i = 1;i<len2;++i)
        for(int j = 1;j<len1;++j)
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
    for(int i = 0;i<len2;++i){
        for(int j = 0;j<len1;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }


    int ans = dp[len2-1][len1-1];
    cout<<ans<<endl;

}
