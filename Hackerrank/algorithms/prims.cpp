// @da
#include<bits/stdc++.h>
using namespace std;
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
const int MAX = 3*int(1e3) + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{   /*
    #ifndef ONLINE_JUDGE
        f_in("inp.txt");
        f_out("out.txt");
    #endif // ONLINE_JUDGE
    */
    int nodes, edges, x, y;
    long long weight, minimumCost;
    //cin >> nodes >> edges;
    scanf("%d %d", &nodes, &edges);
    int total = 0;
    for(int i = 0;i < edges;++i)
    {
        //cin >> x >> y >> weight;
        scanf("%d %d %lld", &x, &y, &weight);
        total += weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    //int source;
    //scanf("%d", &source);
    minimumCost = prim(nodes);
    //cout << minimumCost << endl;
    printf("%lld", abs(minimumCost));
    return 0;
}
