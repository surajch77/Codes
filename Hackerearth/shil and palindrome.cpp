#include<bits/stdc++.h>
using namespace std;
int tree[100007][27];
int n, q;
void update(int id, int val, int pos){
    for(; id<=n; id += id&(-id))
        tree[id][pos] += val;
}
int query(int id, int pos){
    int ans = 0;
    for(;id>0; id -= id&(-id))
        ans += tree[id][pos];
    return ans;
}
int main(){
    scanf("%d %d", &n, &q);
    string s;
    cin >> s;
    for(int i=0; i<s.size(); ++i)
        update(i+1, 1, s[i] - 'a');
    while(q--){
        int t;
        scanf("%d", &t);
        if(t==1){
            int id;
            char ch;
            cin >> id >> ch;
            update(id, 1, ch-'a');
            update(id, -1, s[id-1] - 'a');
            s[id-1] = ch;
        }
        else{
            int l, r;
            cin >> l >> r;
            int odd = 0, val;
            for(int i=0; i<26; ++i){
                val = query(r, i) - query(l-1, i);
                if(val&1)
                    ++odd;
            }
            if(odd>1)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
}
