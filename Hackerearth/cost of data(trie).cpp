#include<bits/stdc++.h>
using namespace std;
struct node{
      node *p[27];
      node(){
            for(int i=0; i<27; ++i)
                  p[i] = NULL;
      }
}*root;
void insert(string s){
      node *x = root;
      for(int i=0; i<s.size(); ++i){
            if(x->p[s[i]-'a'] == NULL)
                  x->p[s[i]-'a'] = new node;
            x = x->p[s[i]-'a'];
      }
}
int countnodes(node *x){
      int cnt = 1;
      for(int i=0; i<27; ++i)
            if(x->p[i] != NULL)
                  cnt += countnodes(x->p[i]);
      return cnt;
}
int main(){
      root = new node;
      int n;
      scanf("%d", &n);
      for(int i=0; i<n; ++i){

            string str;
            cin>>str;
            insert(str);
      }
      printf("%d", countnodes(root));
}
