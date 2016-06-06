#include<bits/stdc++.h>
using namespace std;
#define lld long long
lld arr[1234567];
int main(){
            int n, m;
            cin >> n >> m;
            for(int i=0; i<m; ++i){
                    int a, b;
                    lld k;
                    cin >> a >> b >> k;
                    arr[a] += k;
                    if(b+1<=n)
                         arr[b+1] -= k;
                    //for(int i=1; i<=n; ++i)
                       //  cout<<arr[i]<<" ";
                    //cout<<endl;
            }
            //for(int i=1; i<=n; ++i)
               //cout<<arr[i]<<" ";
            //cout<<endl;
          lld maxi = 0;
          lld x = 0;
          for(int i=1; i<=n; ++i){
               x = x+arr[i];
               if(maxi < x)
                    maxi = x;
          }
          cout << maxi;
}
