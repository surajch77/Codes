#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector< vector<pii> > graph;
const int inf = 1e6+9;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        graph.clear();
        graph.resize(n+1);
        vector<vector<int> > dist(n+1, vector<int> (n+1, inf));
        for(int i=1; i<=n; ++i)
            dist[i][i] = 0;
        for(int i=0; i<m; ++i){
            int u, v, c;
            cin >> u >> v >> c;
            //graph[u].push_back(make_pair(v,c));
            //graph[v].push_back(make_pair(u,c));
            dist[u][v] = min(dist[u][v],c);
            dist[v][u] = dist[u][v];
        }
        int s, h, a;
        cin >> s >> a >> h;
        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int ans = 0;
        for(int i=1; i<=n; ++i){
            if(i==s or i==a or i==h)
                continue;
            ans = max(ans, dist[s][i] + 2*dist[i][a] + dist[i][h]);
        }
        cout<<ans<<"\n";
    }
}
