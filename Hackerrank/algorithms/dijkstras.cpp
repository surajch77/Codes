///
#include<bits/stdc++.h>
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
using namespace std;
const int inf = 1<<29;
int n, m, adj[3002][3002], dist[3002];
bool flag[3002];
void dijkstra(int source){
    fill(dist, dist + 3002, inf);
    dist[source] = 0;
    for(int i=1; i<=n; ++i){
        int d = inf, u = 0;
        for(int j=1; j<=n; ++j)
            if(!flag[j] and dist[j] < d)
                d = dist[j], u = j;
        flag[u] = 1;
        for(int j=1; j<=n; ++j)
            if(!flag[j])
                dist[j] = min(dist[j], dist[u] + adj[u][j]);
    }
}
int main(){

    #ifdef ONLINE_JUDGE
        f_in("inp.txt");
        f_out("out.txt");
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    fill_n(&adj[0][0], 3002*3002, inf);

    for(int i=0, u, v, w; i<n; ++i){
        //cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = adj[v][u] = min(adj[u][v], w);

     }
     int source;
     scanf("%d", &source);
     dijkstra(source);
     int q;
     scanf("%d", &q);
     while(q--){
        int i;
        scanf("%d", &i);
				if(flag[i] == true)
					printf("%d\n", dist[i]);
				else
					printf("NO PATH\n");

     }


}
