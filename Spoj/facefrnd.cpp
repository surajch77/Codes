#include<bits/stdc++.h>
using namespace std;
int main(){
     #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     #endif // ONLINE_JUDGE
     int n;
     scanf("%d", &n);
     set<int> s;
     int prev = 0;
     vector<int> ids;
     for(int i=0; i<n; ++i){
          int id;
          scanf("%d", &id);
          ids.push_back(id);
          int bff;
          scanf("%d", &bff);
          for(int j=0, temp; j<bff; ++j)
               scanf("%d", &temp), s.insert(temp);

     }
     for(int i = 0; i<ids.size(); ++i)
          s.erase(ids[i]);
     printf("%d", s.size());
}
