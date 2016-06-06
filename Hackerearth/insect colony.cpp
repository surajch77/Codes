#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int odd = 0, even = 0;
        for(int i = 0; i<n; ++i){
            int temp;
            cin >> temp;
            if(temp%2==0)
                even++;
            else
                odd++;
        }
        if(odd%2==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
}
