#include<bits/stdc++.h>
#include<array>
using namespace std;

int main(){
    array<int,7> arr;
    for(int i = 0; i < arr.size(); ++i )
        cin>>arr[i];

    array<int,7> dp,prev;
    for(int i = 0; i < dp.size(); ++i)
        dp[i] = arr[i] ,prev[i] = i;
    for(int i = 1 ; i < arr.size() ; ++i ){
        for(int j = 0 ; j < i; ++j)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i],dp[j] + arr[i]);

    }
    for(int i = 0;i<dp.size();++i)
        cout<<dp[i]<<" ";

    int ans = *max_element(dp.begin(),dp.end());
    cout<<"Max sum is "<<ans<<endl;

}
