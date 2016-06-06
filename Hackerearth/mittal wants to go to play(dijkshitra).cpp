#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector< vector<pair<int, int> > > graph;
int dist[100006];
int n, q, m;

void dij(int start){
    priority_queue<pii,vector<pii>, greater<pii> > q;
    for(int i=0; i<=n; ++i)
        dist[i] = 1000000000;
    dist[start] = 0;
    q.push(pii(0, start));
    int status = 0;
    while(!q.empty()){
        status++;
        pii top = q.top();
        q.pop();
        int v = top.second, cost = top.first;
        if(cost <= dist[v]){
            for(int i=0; i<graph[v].size(); ++i){
                int v2 = graph[v][i].first, d = graph[v][i].second;
                if(dist[v2] > dist[v] + d){
                    dist[v2] = dist[v] + d;
                    q.push(pii(dist[v2], v2));
                }
            }
        }
        if(status==n)
            return;
    }
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
        graph.resize(n+1);
        for(int i = 0; i < m; ++i){
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            graph[u].push_back(make_pair(v, c));
            graph[v].push_back(make_pair(u, c));
        }
        dij(1);
        scanf("%d", &q);
        while(q--){
            int x, y;
            scanf("%d %d", &x, &y);
            if(2*dist[x]<=y)
	    	cout<<(y-2*dist[x])<<endl;
	    	else
	    	cout<<"0"<<endl;
        }
    }

}
