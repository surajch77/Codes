#include<bits/stdc++.h>
#define INF 0xffffff
using namespace std;
string s, v;
int n, m;
int dp[1003][1003], k[1003][10003];

int main(){
      cin >> s >> v;
      n = s.size();
      m = v.size();
      for(int i=0; i<n; ++i){
            int prev = -1;
            for(int j=0; j<m; ++j){
                  if(s[i] == v[j]) prev = j;
                  k[i+1][j+1] = prev;
            }
      }/*
      cout<<"K"<<endl;
      for(int i=0; i<=n; ++i){
            for(int j=0; j<=m; ++j)
                  cout<<k[i][j]<<" ";
            cout<<endl;
      }*/
      for(int i=1; i<=n; ++i)
            dp[i][0] = 1;
      for(int i=0; i<=m; ++i)
            dp[0][i] = INF;

      for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                  if(k[i][j] == -1)
                        dp[i][j] = 1;
                  else
                        dp[i][j] = min(1+dp[i-1][k[i][j]], dp[i-1][j]);
      /*
      cout<<endl<<endl<<"dp"<<endl;
      for(int i=0; i<=n; ++i){
            for(int j=0; j<=m; ++j)
                  cout<<dp[i][j]<<" ";
            cout<<endl;
      }*/
      printf("%d", dp[n][m]);
}
