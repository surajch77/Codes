#include<bits/stdc++.h>
using namespace std;

int maxn;
int maxlg;
struct node{
     int rank[2];
     int index;
};/// find the lcp
vector<int> kasai(string s, vector<int> &sa)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    for(int i=0; i<n; ++i)
          cout<<lcp[i]<<" ";
    cout<<endl;
    return lcp;
}
/// sort the L struct. if the rank of current half is same then sort according to next half
/// else sort according to the current half
int cmp(struct node a, struct node b){
     return a.rank[0] == b.rank[0] ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}
int main(){
     string str;
     cin >> str;
     maxn = str.size();
     maxlg = log(maxn) / log(2) + 1;

     int P[maxlg][maxn];
     /// first row for rank of string
     /// second row onwards rank of the suffixes
     struct node L[maxn];
     for(int i=0; i<maxn; ++i)
          P[0][i] = str[i] - 'a';

     int step = 1;
     int count = 1;
     /// step will fill the matrix and count will store the number of elements compared
     for(count=1, step=1; count<maxn; count*=2, ++step){
          for(int i=0; i<maxn; ++i){
               /// store rank of current half
               L[i].rank[0] = P[step-1][i];
               /// store the rank of next half
               L[i].rank[1] = i + count < maxn ? P[step-1][i+count]:-1;
               /// store the index of suffix
               L[i].index = i;
          }
          sort(L, L+maxn, cmp);
          /// set the rank of suffixes upto 2^cnt
          for(int i=0; i<maxn; ++i){
               if(i==0)       /// first one
                    P[step][L[i].index] = 0;
               else              /// if both the rank is same then
                    if(L[i].rank[0] == L[i-1].rank[0] and L[i].rank[1]==L[i-1].rank[1])
                         P[step][L[i].index] = P[step][L[i-1].index];
                    else           /// else rank is i
                         P[step][L[i].index] = i;
          }

     }/*
     for(int i=0; i<maxlg; ++i){
          for(int j=0; j<maxn; ++j)
               cout<<P[i][j]<<" ";
          cout<<endl;
     }*/
     vector<int> sa;
     for(int i=0; i<maxn; ++i)
          sa.push_back(P[maxlg-1][i]);
     vector<int> lcp = kasai(str, sa);
     cout<<"suffix array"<<endl;
     for(int i=0; i<maxn; ++i)
          cout<<P[maxlg-1][i]<<" ";
     cout<<endl;
     cout<<"lcp array"<<endl;
     for(int i=0; i<lcp.size(); ++i)
          cout<<lcp[i]<<" ";
     cout<<endl;


}
