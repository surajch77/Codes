/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        double x1, x2, y1, y2, r;

        cin >> x1 >> y1 >> x2 >> y2 >> r;

        double d = sqrt((x2-x1) * (x2-x1) + (y2-y1) *(y2-y1));

        double D = x1 * y2 - x2 * y1;

        double delta = r * r * d * d - D * D;

        if(delta < 0)
            puts("SAFE");
        else
            if(delta == 0)
                puts("JUST MISSED");
            else
                puts("REPLANNING");
    }
}
