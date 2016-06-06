/// @da
#include <bits/stdc++.h>
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
vector< int > graph[1003];
vector<bool> bs(1003);
vector<int> dist(1004);

void bfs(int start){
	queue<int> que;
	que.push(start);
	dist[start] = 0;
	bs[start] = true;
	while(!que.empty()){
		int val = que.front();
		bs[val] = true;
		que.pop();
		for(int i=0; i<graph[val].size(); ++i)
			if(bs[graph[val][i]] == false){
				que.push(graph[val][i]);
				dist[graph[val][i]] = min(dist[graph[val][i]], dist[val] + 1); /// minimum to a point or minimum to itself
			}

	}
}
int main(){
	/*
    #ifndef ONLINE_JUDGE
        f_in("inp1.txt");
        f_out("out.txt");
    #endif // ONLINE_JUDGE
    */
    int test;
    scanf("%d", &test);
    while(test--){
    	int n, m;
    	sc2(n, m);
    	for(int i=0; i<=n; ++i){
    		graph[i].clear();
    		bs[i] = false;
    		dist[i] = 10000000;
		}
		while(m--){
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].pb(b);
			graph[b].pb(a);
		}
		int s;
		scanf("%d", &s);
		bfs(s);
		for(int i = 1;i<=n; ++i){
			if(i not_eq s)
				if(bs[i] == true)
					printf("%d ", dist[i] * 6);
				else
					printf("-1 ");
		}
		printf("\n");

	}

}

