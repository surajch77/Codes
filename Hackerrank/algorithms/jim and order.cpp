/*
@da
*/
#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n;
    scanf("%d", &n);
    vector< pair<int, int> > vi;
    int a, b;
    for(int i=0; i<n; ++i)
		scanf("%d %d", &a, &b), vi.push_back(make_pair(a+b, i+1));
	sort(vi.begin(), vi.end());
	for(int i=0; i<n; ++i)
		printf("%d ", vi[i].second);
}

