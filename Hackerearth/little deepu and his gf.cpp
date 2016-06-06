#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int m, n;
        cin >> m >> n;
        vector<int> arr;
        for(int i=0, temp; i<n; ++i)
            scanf("%d", &temp), arr.push_back(temp);
        vector<int> dp(m+1, 0);
        for(int i=0; i<=m; ++i)
            if(dp[i])
                continue;
            else
                for(int j=0; j<n; ++j)
                    if(arr[j] + i <=m)
                        dp[arr[j] + i] = 1;
        if(dp[m])
            printf("Little Deepu\n");
        else
            printf("Kate\n");
    }
}
