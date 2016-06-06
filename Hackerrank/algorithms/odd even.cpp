#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld pow(lld a, lld b){
    lld ans =  1;
    while(b){
        if(b&1)
            ans *= a;
        a = a*a;
        b>>=1;
    }
    return ans;
}
vector<int> v;
int find(int x, int y){
    if(x>y)
        return 1;
    int ans = pow(v[x], find(x+1, y));
    return ans;
}

int main(){
    int n;
    cin >> n;
    int temp;
    v.push_back(0);
    for(int i=0; i<n; ++i)
        cin >> temp, v.push_back(temp);
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        //int ans = find(x, y);
        //cout<<ans<<endl;
        if(find(x,y) &1)
            cout << "ODD"<<endl;
        else
            cout << "EVEN"<<endl;
    }
}
