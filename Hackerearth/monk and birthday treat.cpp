/// @da
#include<bits/stdc++.h>
using namespace std;
int cnt, n, m;
vector< vector<int> > graph(1000+1);
vector<bool> visited(1002);
void travel(int i){
    visited[i] = true;
    for(int j=0; j<graph[i].size(); ++j){
        if(visited[graph[i][j]] == false){
            cnt++;
            //visited[graph[i][j]] = true;
            travel(graph[i][j]);
        }

    }

}
int main(){
    scanf("%d %d", &n, &m);
    graph.clear();
    int ans = INT_MAX;
    for(int i=0, a, b; i<m; ++i)
        scanf("%d %d", &a, &b), graph[a].push_back(b);
    for(int i=1; i<=n; ++i){
        for(int j=0; j<1001; ++j)
            visited[j] = false;
        cnt = 1;
        travel(i);
        ans = min(cnt, ans);
    }
    printf("%d", ans);

}
