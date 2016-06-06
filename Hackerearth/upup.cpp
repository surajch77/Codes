#include<bits/stdc++.h>
using namespace std;
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    char ch;
    bool flag = true;
    while(scanf("%c", &ch)!=EOF){
        if(ch==' ')
            flag = true;
        if(flag and ch>='a' and ch<='z')
            printf("%c", ch - 32), flag = false;
        else
            printf("%c", ch), flag = false;
    }
}
