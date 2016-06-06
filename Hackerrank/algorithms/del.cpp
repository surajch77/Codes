#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,h,m,cnt,i,j;
	int a[]={0,1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&m);
		cnt=0;
		for(i=0;a[i]<h && i<19;++i)
		{
			for(j=0;a[j]<m && j<19;++j)
			{
				if((a[i]%10)==(a[j]%10)) cnt++, cout << a[i] << " " << a[j] << endl;

			}
			cout << endl;
		}
		printf("%d\n",cnt);
	}
}
