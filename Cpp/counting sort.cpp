#include<bits/stdc++.h>
using namespace std;
int maxi = 0, n;
int counta[10000];
int output[10000];
void counting(int arr[]){
      for(int i=0; i<n; ++i)
            counta[arr[i]]++;
      for(int i=1; i<=maxi; ++i)
            counta[i] += counta[i-1];
      for(int i=0; i<n;++i){
            cout<<"count array"<<endl;
            for(int j=0; j<=maxi; ++j)
                  cout<<counta[j]<<" ";
            cout<<endl;
            cout<<"output array"<<endl<<endl;
            for(int j=0; j<=maxi; ++j)
                  cout<<output[j]<<" ";
            cout<<endl;
            output[counta[arr[i]] - 1] = arr[i], --counta[arr[i]];


      }

      for(int i=0; i<10; ++i)
            cout<<output[i]<<" ";
      cout<<endl;
}
int main(){
      cin >> n;
      int arr[n];
      for(int i=0; i<n; ++i)
            scanf("%i", &arr[i]), maxi = max(arr[i], maxi);
      counting(arr);
}
