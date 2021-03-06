#include <bits/stdc++.h>
#include "assert.h"
using namespace std;


#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define rep(i,a,b) for (int i = a; i < b; ++i)

#define repv(i,cc) rep(i,0,sz(cc))
#define unq(c) sort(all(c)),(c).resize(unique(all(c))-(c).begin())

#define pb push_back
//#define mp make_pair


typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

/* INF use INT_MAX INT_MIN, LLONG_MIN, LLONG_MAX , ULLONG_MAX */

#define is(a) scanf("%d",&a)
#define iull(a) scanf("%llu",&a)
#define pull(a) printf("%llu\n",a)
#define db(a) scanf("%lf",&a)
#define pc(a) putchar(a)
#define pl(a) printf("%lld\n",a)
#define pu(a) printf("%u\n",a)
#define pd(a) printf("%lf\n",a)
#define ps(a) puts(#a)

#define pi(x) cerr<<"Debug: "<< #x << " : "<< x<<"\n";
#define pts(a) puts(a)
#define MAX 1000009
#define EPS 1e-7


template<class T> inline string tostring( T n ){ stringstream ss; ss << n; ss.flush(); return ss.str(); }
template<class T> inline string tobinary( T n ){ string s = n ? "" : "0"; while( n ) { s += ( ( n & 1 ) + '0' ); n >>= 1; } return s; }
template<class T> inline int digits( T n ){ int cnt = n ? 0 : 1; while( n ){ n /= 10; cnt++; } return cnt; }
template<class T1, class T2> inline T2 gcd( T1 a, T2 b ){ return !b ? a : gcd( b, a%b ); }
template<class T> inline T abs( T a ){ return a < 0 ? -a : a; }

#ifndef _FOOLS_SYS_
    #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();i++)
    #define gc getchar_unlocked
    #define ugc ungetc
#else
    #define tr(c,i) for(decltype((c).begin()) i = (c).begin(); i != (c).end();i++)
    #define gc getchar
    #define ugc ungetchar
#endif

#define i(n) { \
	register char chchchch = 0, \
	              sssssssss = 1; \
	n = 0; \
	for(;chchchch < 33;chchchch = gc()); \
	(chchchch == 45)?sssssssss = -1,chchchch = gc():0; \
	for(;chchchch > 33;n = n * 10 + chchchch - '0',chchchch = gc()); \
	n *= sssssssss; \
}

const int MX = 4000009;
char s[MX];
char t[1000009];
int z[MX];

int main(){

         #ifdef _FOOLS_SYS_
            freopen("input.txt","r",stdin);
         #else
           // ios_base::sync_with_stdio(false);
         #endif

         int N;
         scanf("%d", &N);

         scanf("%s",s);
         s[N] = '$';
         scanf("%s",t);
         strcpy(s+N+1,t);
         strcpy(s+strlen(s),t);


         int n = strlen(s);
         cout<<s<<endl;
         int L = 0, R = 0;
         for (int i = 1; i < n; i++) {
            if (i > R) {
                  L = R = i;
                  while (R < n && s[R-L] == s[R])
                        R++;
                  z[i] = R-L; R--;
            }
            else {
                  int k = i-L;
                  if (z[k] < R-i+1)
                        z[i] = z[k];
                  else {
                        L = i;
                        while (R < n && s[R-L] == s[R])
                              R++;
                        z[i] = R-L; R--;
                  }
            }
      }
            for(int i=0; i<n;++i)
                  cout<<z[i]<<" ";
            cout<<endl;
         int ans;
         int mx = INT_MIN;
         for(int i = N+1; i <= 3*N; ++i){
            if(mx < z[i]){
              ans = i - (N + 1);
              mx = z[i];
              //pi(i);
              //pi(ans);
            }
         }

         printf("%d\n",ans);

         return 0;
}
