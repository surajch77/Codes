#include<bits/stdc++.h>
#define MAX 12345
using namespace std;

void sequence(int arr[],int n,int dp[]){
        for(int i = 1;i<n;++i)
            for(int j = 0;j<i;++j)
                if(arr[j]<arr[i])
                    dp[i] = max(dp[i],dp[j]+1);

}

int main(){
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        int arr[n],fdp[n],bdp[n],dp[n];
        for(int i = 0;i<n;++i)
            scanf("%d",arr+i),fdp[i] = bdp[i] = 1;
        sequence(arr,n,fdp);
        reverse(arr,arr+n);
        sequence(arr,n,bdp);
        reverse(bdp,bdp+n);
        int maxi = 0;
        for(int i = 0;i<n;++i)
            if((dp[i] = fdp[i]+bdp[i]-1)>maxi)
                maxi = dp[i];
        cout<<maxi<<endl;

}
