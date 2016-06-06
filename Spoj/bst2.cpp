#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
      int n, root;
      scanf("%d", &n);
      map<int, lld> tree;
      lld c = 0, val = 0;
      while(n--){
            int node;
            scanf("%d", &node);
            tree[node] = 0;
            if(tree.size() == 1){
                  printf("%lld\n", val);
                  root = node;
                  continue;
            }
            int right = 0, left = 0;
            map<int, lld>::iterator it = tree.find(node);
            map<int, lld>::iterator prev = it;
            if(node > root){
                  if(++it != tree.end())
                        right = it->second;
                  left = (--prev)->second;
            }
            else{
                  right = (++it)->second;
                  if(prev != tree.begin())
                        left = (--prev)->second;
            }
            val = max(right, left);
            val++;
            tree[node] = val;
            c += val;
            printf("%lld\n", c);
      }
}
