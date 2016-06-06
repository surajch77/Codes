#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
     int n;
     while(cin >> n){
          string text, pattern;
          cin >> pattern;
          cin >> text;
          int t_len = text.size();
          int p_len = pattern.size();
          int p = 31;
          vector<lld> pw( max( t_len, p_len ));
          pw[0] = 1;
          /// for ith power of base
          for(int i=1; i<pw.size(); ++i)
               pw[i] = pw[i-1] * p;
          vector<lld> h(t_len);
          /// find the hash of text;
          for(size_t i=0; i<t_len; ++i){
               h[i] = (text[i] - 'a' + 1) * pw[i];
               if(i) h[i] += h[i-1];
          }

          ///find the has of the pattern
          lld hp = 0;
          for(size_t i=0; i<p_len; ++i)
               hp += (pattern[i] - 'a' + 1) * pw[i];
          bool flag = false;
          /// find the pattern in the string;
          for(size_t i=0; i+p_len-1 < t_len; i++){
               lld cur_h = h[i+p_len-1];
               if(i) cur_h -= h[i-1];
               if(cur_h == hp * pw[i])
                    flag = true, cout << i << endl;
          }
          if(!flag)
               cout<<endl<<endl;
     }



}
