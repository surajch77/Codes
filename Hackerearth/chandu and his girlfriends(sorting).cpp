#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        vector<int> a;
        for(int i=0, temp; i<n+m; ++i){
            scanf("%d", &temp);
            a.push_back(temp);
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for(int i=0; i<n+m; ++i)
            printf("%d ", a[i]);
        printf("\n");

    }
}
