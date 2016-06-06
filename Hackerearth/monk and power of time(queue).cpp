#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> calling , ideal;
    for(int i=0; i<n; ++i){
        int temp;
        cin >> temp;
        calling.push(temp);
    }
    for(int i=0; i<n; ++i){
        int temp;
        cin >> temp;
        ideal.push(temp);
    }
    int ans = 0;
    while(!ideal.empty()){
        if(ideal.front() == calling.front()){
            ideal.pop();
            calling.pop();
        }
        else{
            ans++;
            int val = calling.front();
            calling.push(val);
            calling.pop();
        }
    }
    cout<<ans+n<<endl;

}
