#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector< vector<int> > dp;//(n+1,vector<int> (n+1,0));
    dp.resize(100);
    for(int i=0; i<=n; ++i)
        dp[i].push_back(i);
    /*
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=n;++j)
            cout<<dp[i][j]<<" ";
    cout<<endl;
    }
*/
}
