#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        vector< vector<int> > graph(n+1);
        for(int i = 0; i < m; ++i){
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visit(n+1, false);
        vector<int> dist(n+1, 0);
        q.push(1);
        visit[1] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0; i<graph[u].size(); ++i){
                if(visit[graph[u][i]] == false){
                    dist[graph[u][i]] = dist[u] + 1;
                    q.push(graph[u][i]);
                    visit[graph[u][i]] = true;
                }
            }
        }
        //cout << "hellow"<<endl;
        printf("%d\n", dist[n]);
    }

}
