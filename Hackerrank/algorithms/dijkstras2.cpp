// @da
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
vector< vector <pair<int, int> > > graph;
int n,m;
int dist[100004];
int lim = 1000000000;
bool flag[10004];
void dij(int start)
{
      priority_queue<pii,vector<pii>, greater<pii> > Q;
      for(int i=1;i<=n;i++)
        dist[i]=lim;
      dist[start] = 0;
      Q.push(pii(0,start));
      int cc=0;
      flag[start] = true;
      while(!Q.empty())
      {
            cc++;
            pii top = Q.top();
            Q.pop();
            int v = top.second, d = top.first;
            flag[v] = true;
            if(d <= dist[v])
            {
                  for(int i=0;i<graph[v].size();i++){
                        int v2 = graph[v][i].first, cost = graph[v][i].second;
                        if(dist[v2] > dist[v] + cost)
                        {
                              // update distance if possible
                              dist[v2] = dist[v] + cost;
                              // add the vertex to queue
                              Q.push(pii(dist[v2], v2));
                        }
                  }
            }
            //if(cc==n)
            //return ;
      }
}
int main(){
    /*
    #ifndef ONLINE_JUDGE
        f_in("inp.txt");
        f_out("out.txt");
    #endif // ONLINE_JUDGE
    */
    scanf("%d", &n);
    graph.clear();
    graph.resize(n+1);

    for(int i=0, u, v, w; i<n; ++i){
        //cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
     int source;
     scanf("%d", &source);
     dij(source);
     int neg = -1;
     int q;
     scanf("%d", &q);
     while(q--){
            int i;
            scanf("%d", &i);
				if(flag[i] == true){
                        if(dist[i]>=lim)
                            printf("NO PATH\n");
                        else
                            printf("%d\n", dist[i]);
				}

				else
					printf("NO PATH\n");
		}
}


