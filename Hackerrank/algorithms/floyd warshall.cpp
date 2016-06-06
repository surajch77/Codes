// @da
#include<bits/stdc++.h>
using namespace std;
const int INT_MAXu = 1<<29;
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
int main(){

     #ifndef ONLINE_JUDGE
        f_in("inp.txt");
        f_out("out.txt");
    #endif // ONLINE_JUDGE

    int n, m;
    scanf("%d %d", &n, &m);
    int dist[n+1][n+1];
    bool flag[n+1][n+1];
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
            dist[i][j] = INT_MAXu, flag[i][j] = false;

    while(m--){
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        dist[u][v] = weight;
        flag[u][v] = true;
    }
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j){
                    if(flag[i][k] and flag[k][j])
                        flag[i][j] = true;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            }

    int query;
    scanf("%d", &query);
    int ans = -1;
    while(query--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a==b)
            printf("0\n");

        else{
                if(flag[a][b])
                    printf("%d\n", dist[a][b]>=INT_MAXu ? ans: dist[a][b]);
                else
                    printf("-1\n");

        }

    }
}
