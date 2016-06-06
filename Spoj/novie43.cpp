#include<bits/stdc++.h>
using namespace std;

int mat[13][12];

void display(){
	for(int i=1;i<13;i++){
		for(int j=1;j<12;j++)
			printf("%8d", mat[i][j]);
		printf("\n");
	}
	//system("pause");
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
	for(int i=1;i<13;i++)
		for(int j=1;j<12;j++)
			mat[i][j] = 0;
	mat[1][1] = 1;
	mat[12][1] = 1;

	for(int j=2;j<12;j++){
		for(int i=1;i<j;i++){
			mat[i][j] += mat[i][j-1] * i;
			mat[i+1][j] += mat[i][j-1];
		}

		for(int i=1;i<12;i++)
			mat[12][j] += mat[i][j];

		//display();
	}

	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", mat[12][n]);
	}
    return 0;
}
