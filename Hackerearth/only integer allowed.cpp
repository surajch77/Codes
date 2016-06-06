/// #sh

#include<bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
    int n;

    cin >> n;

    int x[n+1], y[n+1];

    for(int i=0; i<n; ++i)
        cin >> x[i] >> y[i];

    x[n] = x[0];
    y[n] = y[0];

    lld area = 0;

    for(int i=0; i<n; ++i)
        area += (1LL * x[i+1] * y[i] - 1LL * x[i] * y[i+1]);

    int lines = 0;

    for(int i=0; i<n; ++i)
        lines += __gcd(abs(y[i+1] - y[i]), abs(x[i+1] - x[i]));

    //cout << area << endl << lines << endl;

    cout << (area + 2 - lines) / 2 << endl;

}

/*
#include <bits/stdc++.h>
using namespace std;

int n,x[1<<20],y[1<<20];
long long s;
int bord;

int gcd(int a,int b)
{
	a=abs(a);
	b=abs(b);
	while (a&&b)a>b?a-=b:b-=a;
	return a+b;
}

int main(){


cin>>n;
for (int i=0;i<n;i++)
{
	cin>>x[i]>>y[i];
}


x[n]=x[0];
y[n]=y[0];
for (int i=0;i<n;i++)
	s+=1ll*x[i+1]*y[i]-1ll*x[i]*y[i+1];
for (int i=0;i<n;i++)
	bord+=gcd(y[i+1]-y[i],x[i+1]-x[i]), cout << gcd(y[i+1]-y[i],x[i+1]-x[i]) << endl;

cout << s << endl << bord << endl;
cout<<(s+2-bord)/2<<endl;
return 0;}
*/
