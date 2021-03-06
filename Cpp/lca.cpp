#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
#include <cassert>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long

using namespace std;

#define maxn 300111
#define logN 20

vector <int> adj[maxn];
int f[maxn][logN], depth[maxn], n;

void dfs(int u) {
    for (int i = 1; i < logN; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!depth[v]) {
            f[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int lca (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = logN - 1; i >= 0; i--)
        if (depth[f[u][i]] >= depth[v]) {
            u = f[u][i];
        }

    if (u == v) return u;

    for (int i = logN - 1; i >= 0; i--)
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }

    return f[u][0];
}

int dist (int u, int v) {
    int x = lca(u, v);
    int res = depth[u] + depth[v] - 2 * depth[x];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);
    while(1){
      int x, y;
      cin >> x >> y;
      cout<<lca(x, y);
    }

    int q;
    cin >> q;

    pair<int, int> p[6];
    while (q--) {
        int u, v, r;

        cin >> r >> u >> v;

        p[0].second = u;
        p[1].second = v;
        p[2].second = r;
        p[3].second = lca(r, u);
        p[4].second = lca(r, v);
        p[5].second = lca(u, v);

        for (int i = 0; i < 6; i++) {
            int x = p[i].second;
            p[i].first = dist(x, r) + dist(x, u) + dist(x, v);
        }

        sort(p, p + 6);

        cout << p[0].second << endl;
    }
}
