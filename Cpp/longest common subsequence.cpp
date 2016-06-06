#include<bits/stdc++.h>
using namespace std;
/*
int m[2][1000];

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int M = s1.length();
    int N = s2.length();


    for(int i=M; i>=0; --i){
        int ii = i&1;
        for(int j=N; j>=0; --j){
            if(i==M or j==N){ m[ii][j]=0;continue;}
            if(s1[i]==s2[j]) m[ii][j] = 1+m[1-ii][j+1];
            else m[ii][j] = max(m[ii][j+1], m[1-ii][j]);
        }
        for(int k=0; k<2;++k){
            for(int l=0; l<=15;++l)
                cout<<m[k][l]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<m[0][0]<<endl;


}
*/
#define Max 10005
int dp[Max][Max];
int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int len1 = str1.size();
    int len2 = str2.size();

    len1++;
    len2++;
    //int dp[len2][len1];

    for(int i = 0 ; i < len1; ++i)
        dp[0][i] = 0;
    for(int i = 0 ; i < len2; ++i)
        dp[i][0] = 0;

    for(int i = 1 ; i < len2 ; ++i)
        for(int j = 1 ; j < len1 ; ++j)
            if(str2[i-1] == str1[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    for(int i = 0;i<len2;++i){
        for(int j = 0;j<len1;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    int ans = dp[len2-1][len1-1];
    cout<<ans<<endl;
}
