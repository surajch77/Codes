#include<iostream>
#include<vector>
using namespace std;

int div2[1000001];
bool p[1000001];

int main(){
    for(int i=2;i<1000001;i++)
        div2[i]=1;
    for(int i=2;i<1000001;i++)
        p[i]=1;
    for(long long i=2;i<1000001;i++){
        if(p[i]==0)
            continue;
        div2[i]=0;
        for(long long j=i*2;j<1000001;j+=i){
            p[j]=0;
        }
        long long k;
        //cout<<i<<endl;
        for(long long j=1,k=i*i;k<1000001;j++,k=i*i*j){
            div2[k]=0;
        }
    }
    int c=0;
    for(int i=2;i<1000001;i++){
        if(div2[i]==1){
            c++;
            if(c%108==0) cout<<i<<endl;
        }
    }
    return 0;
}
