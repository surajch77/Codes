#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
    int n;
    cin >> n;
    priority_queue<int> p;
    int temp;
    for(int i=0; i<n; ++i){
        cin >> temp;
        p.push(temp);
        if(i<=1)
            cout<<-1<<endl;
        else{
            int first = p.top();
            p.pop();
            int second = p.top();
            p.pop();
            int third = p.top();
            p.pop();
            p.push(first);
            p.push(second);
            p.push(third);
            lld ans = (lld)first * (lld)second * (lld)third;
            cout<<ans<<endl;
        }
    }
}
