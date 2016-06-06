/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        cin >> n;
        char arr[n][n];
        for(int i=0; i<n; ++i)
            scanf("%s", arr[i]), sort(arr[i], arr[i]+n);

        bool fnd = false;
        for(int i=0; i<n; ++i){
            if (fnd)
                break;
            for(int j=0; j<n-1; ++j)
                if(arr[j+1][i] < arr[j][i])
                    fnd = true;
        }

        if(!fnd)
            puts("YES");
        else
            puts("NO");

    }
}
