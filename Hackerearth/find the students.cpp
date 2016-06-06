#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int n;
    cin >> n;
    vector<int> v(1005, 0);
    for(int i=0, temp; i<n; ++i){
        scanf("%d", &temp);
        //v.push_back(temp);
        v[temp] += 1;
    }
    for(int i =0; i<1001; ++i){
        if(v[i]==0)
            continue;
        else{
            printf("%d\n", n);
            n = n-v[i];
        }
    }

}
