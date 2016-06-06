#include<bits/stdc++.h>
using namespace std;

vector<int> cnt(100007, 0);

int main(){
    int n;
    cin >> n;
    priority_queue<int> pmax;
    priority_queue<int, vector<int>, greater<int> > pmin;
    while(n--){
        int q;
        cin >> q;
        if(q==1){
            int x;
            cin >> x;
            cnt[x]++;
            pmax.push(x);
            pmin.push(x);
        }
        if(q==2){
            int x;
            cin >> x;
            if(cnt[x])
                cnt[x]--;
            else
                printf("-1\n");
        }
        if(q==3){
            while(pmax.size() and cnt[pmax.top()] == 0)
                pmax.pop();
            if(pmax.size())
                printf("%d\n", pmax.top());
            else
                printf("-1\n");
        }
        if(q==4){
            while(pmin.size() and cnt[pmin.top()] == 0)
                pmin.pop();
            if(pmin.size())
                printf("%d\n", pmin.top());
            else
                printf("-1\n");
        }
    }
}
