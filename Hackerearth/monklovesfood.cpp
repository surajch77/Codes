#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    stack<int> s;
    while(q--){
        int q;
        cin >> q;
        if(q==1){
            if(!s.empty()){
                cout<<s.top()<<endl;
                s.pop();
            }
            else
                cout<<"No Food\n";

        }
        else{
            int val;
            cin >> val;
            s.push(val);
        }

    }
}
