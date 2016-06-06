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

    for(int i = 0 ; i < len1; ++i)
        dp[0][i] = 0;
    for(int i = 0 ; i < len2; ++i)
        dp[i][0] = 0;

    for(int i = 1 ; i < len2 ; ++i)
        for(int j = 1 ; j < len1 ; ++j)
            if(str2[i-1] == str1[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
    int maxi = 0;
    for(int i = 0;i<len2;++i){
        for(int j = 0;j<len1;++j)
            maxi = max(dp[i][j],maxi);
    }

    int ans = maxi;
    cout<<ans<<endl;
}
