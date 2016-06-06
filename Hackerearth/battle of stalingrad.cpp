/// #sh

#include<bits/stdc++.h>

using namespace std;

long double area(int x1, int y1, int x2, int y2, int x3, int y3){
    long double ans = ((x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2))/ 2.0);

    return fabs(ans);
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    long double total_area = area(x1, y1, x2, y2, x3, y3);
    long double area1 = area(x4, y4, x1, y1, x2, y2);
    long double area2 = area(x4, y4, x1, y1, x3, y3);
    long double area3 = area(x4, y4, x2, y2, x3, y3);

    return (total_area == area1 + area2 + area3);
}
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int x1, y1, x2, y2, x3, y3, x4, y4;

        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if(check(x1, y1, x2, y2, x3, y3, x4, y4))
            puts("INSIDE");
        else
            puts("OUTSIDE");
    }
}

