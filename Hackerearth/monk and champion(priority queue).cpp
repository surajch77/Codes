#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    //vector<int> arr;
    int ans = 0;
    priority_queue<int> p;
    for(int i=0; i<m; ++i){
        int temp;
        cin >> temp;
        p.push(temp);
    }
    for(int i=0; i<n; ++i){
        int val = p.top();
        p.pop();
        ans += val;
        if(--val)
            p.push(val);
    }
    cout<<ans<<endl;
}
