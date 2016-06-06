/// #sh

#include<bits/stdc++.h>

using namespace std;

//void evaluate()

int calculate(vector<int> &v, int k){

    vector<int> dp(k+1, 0);
    for(int w = 1; w<=k; ++w){
        for(int i=0; i<v.size(); ++i)
            if(v[i]<=w)
                dp[w] = max(dp[w], v[i] + dp[w-v[i]]);
    }
    return dp[k];
}
int main(){

    int test;
    scanf("%d", &test);
    while(test--){

        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> arr(n, 0);

        for(int i=0; i<n; ++i)
            cin >> arr[i];

        cout << calculate(arr, k) << endl;
    }

}
