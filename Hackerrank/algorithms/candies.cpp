#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      scanf("%d", &n);
      vector<int> r;
      for(int i=0, temp; i<n; ++i)
            scanf("%d", &temp), r.push_back(temp);
      int ans;
      if(n<=1)
            ans = 1;
      else{
            vector<int> res(n, 1);
            for(int i=1; i<n; ++i)
                  if(r[i] > r[i-1])
                        res[i] = res[i-1] + 1;
            for(int i=n-1; i>0; --i)
                  if(r[i-1] > r[i])
                        res[i-1] = max(res[i-1], res[i] + 1);
            ans = 0;
            for(int i=0; i<n; ++i)
                  ans += res[i];
      }
      printf("%d", ans);
}
