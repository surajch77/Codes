#include<bits/stdc++.h>
using namespace std;

int main(){
      float arr[10005];
      arr[0] = arr[1] = 0;
      for(int i=2; i<10005; ++i)
            arr[i] = arr[i-1] + 1./i;
      int t;
      scanf("%d", &t);
      while(t!=0){
            printf("With %d competitors, a Jedi Knight will be replaced approximately %.2f times.\n", t, arr[t]);
            scanf("%d", &t);
      }
}
