#include<bits/stdc++.h>
using namespace std;
#define maxn (int)1e5 + 5
struct trie{
      bool isleaf;
      trie* child[12];
      trie(){
            for(int i=0; i<12; ++i)
                  child[i] = NULL;
      }
}*head;
void insert(string str){
      trie *current = head;
      for(int i=0; i<str.size(); ++i){

            if(current->child[str[i]-'a'] == NULL){
                  current->child[str[i]-'a'] = new trie;
            }

            current->child[str[i]-'a']->isleaf = false;
            current = current->child[str[i]-'a'];

      }
      current->isleaf = true;
}
bool isprefix(string word){
      trie* current = head;
      for(int i=0; i<word.size(); ++i){

            current = current->child[word[i]-'a'];
            if(!current)
                  return false;
            if(current and current->isleaf)
                  return true;

      }
      if(!current->isleaf)
            return true;
      return false;
}
int main(){
      head = new trie;
      head->isleaf = false;
      int n;
      scanf("%d", &n);
      for(int i=0; i<n; ++i){
            string str;
            cin >> str;
            if(isprefix(str)){
                  cout <<"BAD SET"<<endl<<str<<endl;
                  return 0;
            }

            else
                  insert(str);
      }

}
