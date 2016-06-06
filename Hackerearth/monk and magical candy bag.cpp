#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        priority_queue<lld> pq;
        lld temp;
        for(int i=0; i<n; ++i){
            scanf("%lld", &temp);
            pq.push(temp);
        }
        lld sum = 0;
        for(int i=0; i<k; ++i){
            temp = pq.top();
            sum += temp;
            pq.pop();
            pq.push(temp/2);
        }
        printf("%lld\n", sum);
    }

}

