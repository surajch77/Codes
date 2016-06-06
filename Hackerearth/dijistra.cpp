#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define gc getchar_unlocked
vector< vector<pii> >orig;
int n,m;
int dist[100004];
int lim=1000000000;
void dij(int start)
{
      priority_queue<pii,vector<pii>, greater<pii> > Q;
      for(int i=1;i<=n;i++)
        dist[i]=lim;
     dist[start] = 0;
      Q.push(pii(0,start));
      int cc=0;
      while(!Q.empty())
      {
            cc++;
            pii top = Q.top();
            Q.pop();
            int v = top.second, d = top.first;
            if(d <= dist[v])
            {
                  for(int i=0;i<orig[v].size();i++){
                        int v2 = orig[v][i].first, cost = orig[v][i].second;
                        if(dist[v2] > dist[v] + cost)
                        {
                              // update distance if possible
                              dist[v2] = dist[v] + cost;
                              // add the vertex to queue
                              Q.push(pii(dist[v2], v2));
                        }
                  }
            }
            if(cc==n)
            return ;
      }
}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t;
    cin>>t;
    assert(1<=t && t<=10);
    while(t--)
    {
        int i,j,k,x,y,m,c,q;
        cin>>n>>m;

        assert(1<=n && n<=10000);
        assert(1<=m && m<=100000);
        orig.clear();
        orig.resize(n+1);
        rep(i,m)
        {
            cin>>x>>y>>c;
            assert(1<=x && x<=n);
            assert(1<=y && y<=n);
            // if(x==y)
            // {
            //     cout<<x<<" "<<y<<"\n";
            // }
            assert(x!=y);
            assert(1<=c && c<=1000);
            orig[x].pb(mp(y,c));
            orig[y].pb(mp(x,c));
        }
        dij(1);
        cin>>q;
        for(i=1;i<=n;i++)
        {
            assert(dist[i]<lim);
        }
        while(q--)
        {
            cin>>x>>k;
            assert(2<=x && x<=n);
            assert(1<=c && c<=10000);
            cout<<max(0,k-2*dist[x]);
            cout<<"\n";
        }
   }
   return 0;
}
