#include<bits/stdc++.h>
using namespace std;
#define maxn 102
bool dp[maxn][maxn][maxn];
void pre(){
    for(int i=0; i<maxn; ++i)
        for(int j=0; j<maxn; ++j)
            for(int k=0; k<maxn; ++k){
                if( (i>0 and dp[i-1][j][k] == false) or (j>0 and dp[i][j-1][k] == false)
                        or (k>0 and dp[i][j][k-1] == false) or (i>0 and j>0 and dp[i-1][j-1][k] == false)
                            or (i>0 and k>0 and dp[i-1][j][k-1] == false) or (j>0 and k>0 and dp[i][j-1][k-1] == false)
                                or (i>0 and j>0 and k>0 and dp[i-1][j-1][k-1] == false))
                                        dp[i][j][k] = true;
                else
                    dp[i][j][k] = false;
        }

}
int main(){
    pre();
    int test;
    cin >> test;
    while(test--){
        int a, b, c;
        cin >> a >> b >> c;
        if(dp[a][b][c])
            cout << "Ashima\n";
        else
            cout <<"Aishwarya\n";

    }
}
