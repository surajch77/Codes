#include<bits/stdc++.h>
using namespace std;
char grid[101][101];
char ans[101][101];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int r, c;
void answ(char a, char b, int i, int j){
    for(int k = 0; k<4; ++k){
        int ii = i + dr[k];
        int jj = j + dc[k];
        if(ii>=0 and ii <r and jj >=0 and jj<c)
            if(grid[ii][jj] == b)
                ans[ii][jj] = a;
    }
}
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d %d %d", &r, &c, &n);
        for(int i=0; i<r; ++i)
            scanf("%s", grid[i]);
        while(n--){
            memcpy(ans, grid, sizeof grid);
            for(int i=0; i<r; ++i){
                for(int j=0; j<c; ++j){
                    if(grid[i][j] == 'W')
                        answ('W', 'A', i, j);
                    else if(grid[i][j] == 'A')
                        answ('A', 'G', i, j);
                    else
                        answ('G', 'W', i, j);

                }
            }

            memcpy(grid, ans, sizeof grid);
        }
        for(int i=0; i<r; ++i){
            puts(grid[i]);
        }

    }
}
