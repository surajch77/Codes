#include<bits/stdc++.h>
using namespace std;
#define lld long long int
bool cmp(set< pair<int, int> > &s, pair<int, int> &p) {
	set< pair<int, int> >::iterator it;
	for(it=s.begin(); it!=s.end(); it++) {
		if(it->first < p.first && it->second < p.second) return true;
		if(it->first >= p.first) return false;
	}
	return false;
}
int main(){
      int n;
      scanf("%d", &n);
      set<pair<int, int> > s;
      set<pair<int, int> > ::iterator it;
      for(int i=0; i<n; ++i){
            pair<int, int> pi;
            int a, b;
            scanf("%d %d", &a, &b);
            pi.first = a, pi.second = b;
            if(i==0){
                  s.insert(pi);
                  continue;
            }

            if(cmp(s, pi)){
                  s.insert(pi);
                  it = s.find(pi);
                  it++;
                  if(it!=s.end())
                        s.erase(pi);
            }
           // for(set<pair<int, int> >::iterator itt = s.begin(); itt!=s.end(); ++itt)
             //     cout<<"("<<itt->first<<" "<<itt->second<<")"<<" ";
            //cout<<endl;

      }
      printf("%d", s.size());
}
