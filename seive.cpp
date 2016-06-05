/// #sh

#include<bits/stdc++.h>

using namespace std;
#define MAXN 100010
int N;
vector<int> Q;
int S[10], mx;
int msk[] = {1, 10, 100, 1000, 10000};
int D[10][MAXN];
void seive(){
    for(int i = 2; i <= 99999; i++){
        bool flag = true;
        for(int j = 0; j < Q.size() && Q[j] <= sqrt(i); j++)
            if(flag && i % Q[j] == 0){
                flag = false;
                break;
            }
        if(flag)
        {
            Q.push_back(i);
            for(int j = 1, k = 0; j <= 5; j++, k++)
            {
                int tt = i - i / msk[k] % 10 * msk[k];
                D[j][tt]++;
            }
        }
    }
}

int dfs(int b)
{
    if(b == mx) return D[1][S[mx] * 10];
    int res = 0, vv;
    for(int i = 0; i < msk[mx - b]; i++)
        if((vv = D[mx - b + 1][S[b] * msk[mx - b + 1] + i]) != 0)
        {
            for(int j = mx, k = i; j >= b + 1; j--, k /= 10)
                S[j] = S[j] * 10 + k % 10;
            res += dfs(b + 1) * vv;
            for(int j = mx; j >= b + 1; j--)
                S[j] /= 10;
        }
    return res;
}

int main(){
    #ifdef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    memset(D, 0, sizeof(D));
    seive();
    for(int i = 0; i < N; i++){
        int p, pp, tt;
        scanf("%d", &p);
        mx = 0, pp = p;
        memset(S, 0, sizeof(S));
        while(pp)
            mx++, pp /= 10;
        pp = p, tt = mx;
        while(pp)
            S[tt--] = pp % 10, pp /= 10;
        int ans = dfs(2);
        printf("%d\n", ans);
    }

    return 0;
}
