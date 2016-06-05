#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > graph;
#define maxn 1e5
bool visited[maxn];
vector<int> ans;
int n;
void dfs(int i){
    if(visited[i])
        return;
    visited[i] = true;
    for(int j = 0; j<graph[i].size(); ++j)
        if(!visited[graph[i][j]])
            dfs(i);
    ans.push_back(i);
}
void topological_sort(int i){
    for(int i=0; i<n; ++i)
        visited[i] = false;
    ans.clear();
    for(int i=1; i<=n; ++i)
        if(!visited[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
}


int main(){

}
