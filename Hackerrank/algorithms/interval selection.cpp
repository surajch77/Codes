/// #sh

#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> first, pair<int, int> second){
    return first.second < second.second;
}
int main(){
    int test;
    scanf("%d", &test);
    while(test--){

        int n;
        scanf("%d", &n);
        vector<int> x;

        pair<int, int> a[1002];
        bool flag[1001];
        for(int i=0; i<n; ++i){
            scanf("%d %d", &a[i].first, &a[i].second);
            if(a[i].second < a[i].first)
                swap(a[i].second, a[i].first);
            x.push_back(a[i].second);
            flag[i] = true;
        }

        sort(x.begin(), x.end());
        sort(a, a+n, cmp);

        for(int i=0; i<n; ++i)
            cout << a[i].first << " " << a[i].second << endl;
        for(int i=0; i<n; ++i){
            int cnt = 0;
            for(int j=0; j<n; ++j){
                if(flag[j]){
                    if(a[j].first <= x[i] and a[j].second >= x[i]){
                        cnt++;
                        if(cnt > 2)
                            flag[j] = false;
                    }

                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; ++i)
            ans += flag[i];

        cout << ans << endl;
    }
}

