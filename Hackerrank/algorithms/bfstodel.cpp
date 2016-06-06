#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)


const int N = int(1e4)+1;
const int M = int (1e5)+1;
VI g[N];
int dist[N];
int vis[N];
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
int main()
{

	int t;si(t);
	while(t--)
	{
		int n,m;
		si(n);si(m);
		//assert(n<N);
		//assert(m<M);
		for(int i=0;i<m;i++)
		{
			int u,v;
			si(u);si(v);
			g[u].PB(v);
			g[v].PB(u);
		}
		queue<int> Q;
		int source;
		scanf("%d", &source);
		Q.push(source);
		vis[source]=1;
		dist[source]=0;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int i=0;i<SZ(g[u]);i++)
				if(!vis[g[u][i]])
				{
					dist[g[u][i]]=dist[u]+1;
					Q.push(g[u][i]);
					vis[g[u][i]]=1;
				}
		}
        for(int i = 1;i<=n; ++i){
			if(i not_eq source)
				if(vis[i] == true)
					printf("%d ", dist[i] * 6);
				else
					printf("-1 ");
		}
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			vis[i]=0;
		}
	}
	return 0;
}
