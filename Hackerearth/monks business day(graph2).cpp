#include<bits/stdc++.h>
using namespace std;

int n, m;
#define pii pair<int, int>
const int inf = 1e+8;
struct edge{
    int u, v, c;
};
vector<int> dist;
vector<edge> graph;

bool bellmon_ford(int source){
    dist.clear();
    dist.resize(n+1, inf);
    dist[source] = 0;
    for(int i=0; i<n;++i){
        for(int j=0; j<m; ++j){
            int u = graph[j].u;
            int v = graph[j].v;
            int c = graph[j].c;

            if(dist[u]!=inf)
                dist[v] = min(dist[v], dist[u]+c);
            //for(int i=1; i<=n; ++i)
               // cout<<dist[i]<<" ";
            //cout<<endl;
        }
    }
    //for(int i=1; i<=n; ++i)
       // cout<<dist[i]<<" ";
    //cout<<endl;
    for(int i=0; i<m; ++i){
        int u = graph[i].u;
        int v = graph[i].v;
        int c = graph[i].c;
        if(dist[u]!=inf and dist[u]+c < dist[v])
            return 1;
    }
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        graph.clear();
        graph.resize(m);
        for(int i=0; i<m; ++i){
            int u, v, c;
            cin >> u >> v >> c;
            c = -c;
            graph[i].u = u;
            graph[i].v = v;
            graph[i].c = c;
        }
        if(bellmon_ford(1))
            puts("Yes");
        else
            puts("No");
    }
}
