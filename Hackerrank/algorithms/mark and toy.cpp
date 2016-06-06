/**
@da
**/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, temp;
    scanf("%d", &n);
    bitset<10007> bs;
    bs.reset();
    int torun = 0;
    for(int i=0; i<n; ++i)
        scanf("%d", &temp), bs.set(temp), torun = max(torun, temp);
    int i = 0;
    int counter = 0;
    while(i<=torun){
        if(bs[i] == 1)
            i += 5, counter++;
        else
            i++;

    }
    printf("%d", counter);

}
