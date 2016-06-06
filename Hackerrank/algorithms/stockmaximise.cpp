#include<bits/stdc++.h>
using namespace std;

int main(){
      int test;
      scanf("%d", &test);
      while(test--){
            int n;
            scanf("%d", &n);
            vector<int> arr;
            for(int i=0, temp; i<n; ++i)
                  scanf("%d", &temp), arr.push_back(temp);
            /*
            vector<int> maxv(n,0);
            maxv[n-1] = arr[n-1];
            for(int i=n-2; i>=0; --i)
                  if(arr[i] > maxv[i+1])
                        maxv[i] = arr[i];
                  else
                        maxv[i] = maxv[i+1];
            long long int in = 0, out = 0
            int todo = 0;
            for(int i=0; i<n; ++i)
                  if(arr[i] < maxv[i]){
                        todo++;
                        out += arr[i];
                  }
                  else{
                        in += todo * arr[i];
                        todo = 0;
                  }
            printf("%lld\n", in - out);
            */
            int i = n-1;
            long long int res = 0;
            while(i>0){
                  int localmax = arr[i];
                  while(i>0 and localmax > arr[i-1]){
                        res += localmax - arr[i-1];
                        i--;
                  }
                  i--;
            }
            printf("%lld\n", res);
      }
}
