#include<bits/stdc++.h>
using namespace std;

int main(){
        int test;
        scanf("%d",&test);
        while(test--){
            int n;
            scanf("%d",&n);
            int arr[n],non_cont = 0;
            for(int i = 0;i<n;++i){
                scanf("%d",arr+i);
                if(arr[i]>=0)
                    non_cont+=arr[i];
            }
            int max_eh , max_sf;
            max_eh = max_sf = 0;
            for(int i = 0;i<n;++i)
                max_eh = max(0,max_eh+arr[i]),max_sf = max(max_sf,max_eh);
            int cont = max_sf;
            if(non_cont==0)
                non_cont = *max_element(arr,arr+n);
            if(cont==0)
                cont = *max_element(arr,arr+n);
            printf("%d %d\n",cont,non_cont);


        }
}
