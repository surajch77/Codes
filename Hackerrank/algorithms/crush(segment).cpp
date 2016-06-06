/**
*@da
*/
#include<bits/stdc++.h>
#define MAX 2234567
using namespace std;
#define lld long long int
int arr[MAX], n;
lld tree[4 * MAX], lazy[4 * MAX];

void build(int node, int low, int high, int val){

    if(low > high)
        return;
    if(low == high){
        tree[node] = arr[low];
        return;
    }
    int left = 2 * node + 1;
    int mid = (low + high)/2;
    build(left, low, mid, val);
    build(left + 1, mid + 1, high, val);

    tree[node] = max(tree[left], tree[left + 1]);
}
void lazyupdate(int node, int low, int high, int qlow, int qhigh, lld val){
    if(low > high)
        return;
    //to make sure all nodes are updated
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(low != high){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    //no overlap
    if(qlow > high or qhigh < low)
        return;

    if(qlow <= low and qhigh >= high){
        tree[node] += val;
        if(low != high){
            lazy[2*node + 1] += val;
            lazy[2*node + 2] += val;
        }
        return;
    }

    //partial overlap
    int mid = (low + high) / 2;
    lazyupdate(2*node + 1, low, mid, qlow, qhigh, val);
    lazyupdate(2*node + 2, mid+1, high, qlow, qhigh, val);

   tree[node] = max(tree[2*node + 1], tree[2*node + 2]);

}
lld lazyquery(int node, int low, int high, int qlow, int qhigh){
    if(low > high)
        return -INT_MAX;
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(low != high){
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    //no overlap
    if(qlow > high or qhigh < low)
        return -INT_MAX;

    //total overlap
    if(qlow <= low and qhigh >= high)
        return tree[node];

    //partial overlap
    int mid = (low + high) / 2;
    int q1 = lazyquery(2*node + 1, low, mid, qlow, qhigh);
    int q2 = lazyquery(2*node + 2, mid + 1, high, qlow, qhigh);

    tree[node] = min(tree[2*node + 1], tree[2*node + 2]);
    return max(q1, q2);

}
int main(){
   // ios::sync_with_stdio(false);
      int m;
      cin >> n >> m;
      for(int i=0; i<n; ++i)
            arr[i] = 0;
      for(int i=0; i<m; ++i){
            int a, b;
            lld k;
            cin >> a >> b >> k;
            lazyupdate(0, 0, n-1, a-1, b-1, k);
      }
      //cout<<"end of updat"<<endl;
      //for(int i=0; i<n; ++i)
            //cout<<lazyquery(0, 0, n-1, i, i)<<" ";
      cout<<lazyquery(0, 0, n-1, 0, n-1)<<endl;
      /*
    int test;
    scanf("%d",&test);
    while(test--){
        int h;
        //cin>>n>>h;
        scanf("%d%d",&n,&h);
        //memset(ans,0,sizeof(ans));
        //memset(tree,n,sizeof(tree));
       // for(int i=0;i<4*MAX;++i)
          //  tree[i] = n;
        for(int i = 0;i<4*n;++i)
            tree[i] = n,lazy[i] = 0;
        //memset(lazy,0,sizeof(lazy));
       // build(0, 0, n-1, n);

        for(int i=0; i<n;++i){
            int a, b;
            scanf("%d%d",&a,&b);
            lazyupdate(0,0,n-1,a,b,-1);
        }
        long long int ans[n];
        for(int i=0; i<n; ++i)
            ans[i] = lazyquery(0,0,n-1,i,i);
        //for(int i=0; i<=n; ++i)
          //  cout<<ans[i]<<" ";
        //cout<<endl;
        for(int i=1; i<n; ++i)
            ans[i] += ans[i-1];
        long long int req = ans[h-1];
        for(int i=1; i<=n-h; ++i)
            req = min(req, ans[i+h-1] - ans[i-1]);
        printf("%lld\n",req);



    }
    */


}
