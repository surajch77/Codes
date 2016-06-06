#include<bits/stdc++.h>
#define lld long long int
using namespace std;
int arr[100][100], n, visited[100][100] = {0};
int xc[] = {0, 0, 1, -1};
int yc[] = {1, -1, 0, 0};
int ans(int x, int y){
    if(x==n-1 and y==n-1 and arr[n-1][n-1] == 0)
        return 1;

    if(x==n or x<0 or y==n or y<0 or visited[x][y] == 1 or arr[x][y] == 1)
        return 0;

    int val = 0;
    for(int i=0; i<4; ++i){
            visited[x][y] = 1;
         val += ans(x+xc[i], y+yc[i]);
        visited[x][y] = 0;
    }

    return val;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> arr[i][j];
    if(arr[n-1][n-1] == 1)
        cout<<0<<endl;
    else
        cout << ans(0, 0)<<endl;

}
