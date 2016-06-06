/// @da
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        vector<int> freq(10,0);
        for(int i=0, temp; i<n; ++i){
            scanf("%d", &temp);
            ++freq[temp%10];
        }

        int cnt = 0;
        for(int i=0; i<10; ++i)
            if(freq[i] > 1)
                cnt += freq[i] - 1;
        printf("%d\n", cnt);
    }
}
