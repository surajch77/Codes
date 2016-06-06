#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
typedef long long int lld;
typedef long ld;

#define replld(i,a,b) \
    for(lld(i)=lld(a);i<=lld(b);i++)
#define repi(i,a,b) \
    for(int(i)=int(a);i<=int(b);i++)

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

//fast input
int scan_d()    {int ip=GETCHAR(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=GETCHAR())if(ip=='-'){flag=-1;ip=GETCHAR();break;}for(;ip>='0'&&ip<='9';ip=GETCHAR())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {int ip=GETCHAR(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=GETCHAR())if(ip=='-'){flag=-1;ip=GETCHAR();break;}for(;ip>='0'&&ip<='9';ip=GETCHAR())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {int ip=GETCHAR(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=GETCHAR())if(ip=='-'){flag=-1;ip=GETCHAR();break;}for(;ip>='0'&&ip<='9';ip=GETCHAR())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {int ip=GETCHAR();llu ret=0;for(;ip<'0'||ip>'9';ip=GETCHAR());for(;ip>='0'&&ip<='9';ip=GETCHAR())ret=ret*10+ip-'0';return ret;}

//fast output

//single line output
void print_d(int n)     {if(n<0){n=-n;PUTCHAR('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;PUTCHAR('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;PUTCHAR('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<21);}

//new line output
void println_d(int n)     {if(n<0){n=-n;PUTCHAR('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;PUTCHAR('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;PUTCHAR('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{PUTCHAR(output_buffer[i]);}while(++i<22);}

int main(){
          int test,j=1;
          test = scan_d();
          while(test--){
          	int n,q;
          	n = scan_d();
          	q = scan_d();
          	int arr[n+1];
			for(int i = 1;i<=n;++i)
		 		  arr[i] = scan_d();
	        int ans[n];
	        ans[1] = 1;
		    for(int i = 2;i<=n;++i)
			   if(arr[i]==arr[i-1])
			      ans[i] = ans[i-1];
				else
				   ans[i] = ans[i-1]+1;
		      int l,r;
		      printf("Case %d:\n",j++);
		      while(q--){
		      	l = scan_d();
			  	r = scan_d();
			  	int total = ans[r]-ans[l]+1;
			  	println_d(total);
			  }


		  }
}



