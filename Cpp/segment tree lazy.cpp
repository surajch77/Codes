#include<bits/stdc++.h>
#define MAX (int)1e+7
using namespace std;

int arr[MAX], tree[4 * MAX], lazy[4 * MAX],n;

void build(int node, int low, int high){
    if(low > high)
        return;
    if(low == high){
        tree[node] = arr[low];
        return;
    }
    int left = 2 * node + 1;
    int mid = (low + high)/2;
    build(left, low, mid);
    build(left + 1, mid + 1, high);

    tree[node] = min(tree[left], tree[left + 1]);
}
void lazyupdate(int node, int low, int high, int qlow, int qhigh, int val){
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
        return;
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
    }

    //partial overlap
    int mid = (low + high) / 2;
    lazyupdate(2*node + 1, low, mid, qlow, qhigh, val);
    lazyupdate(2*node + 2, low, mid, qlow, qhigh, val);

    tree[node] = min(tree[2*node + 1], tree[2*node + 2]);

}
int lazyquery(int node, int low, int high, int qlow, int qhigh){
    if(low > high)
        return INT_MAX;
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
        return INT_MAX;

    //total overlap
    if(qlow <= low and qhigh >= high)
        return tree[node];

    //partial overlap
    int mid = (low + high) / 2;
    lazyquery(2*node + 1, low, mid, qlow, qhigh);
    lazyquery(2*node + 2, mid + 1, high, qlow, qhigh);

    tree[node] = min(tree[2*node + 1], tree[2*node + 2]);

}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    build(0, 0, n-1);

}
