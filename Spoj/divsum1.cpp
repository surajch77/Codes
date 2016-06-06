#include<bits/stdc++.h>
using namespace std;
#define lld long long
int m[5000006];
int divsum(int n){
	int sum = 0;
	for(int i = 1;i<=(int)sqrt(n);++i){
			if(n%i==0)
			    sum+=(2);
			if(i*i==n)
			    sum-=1;

	}
	return sum;
}
int main(){
    for(int i=1; i<5000006; ++i)
            m[i] = divsum(i);
    int test;
    scanf("%d", &test);
    while(test--){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int cnt = 0;
        for(int i=l; i<=r; ++i)
            if(m[i] == k)
                cnt++;
        printf("%d\n", cnt);
    }

}
