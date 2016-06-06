#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE


    scanf("%i", &n);
    while(n != 0){
        vector<unsigned long long int > c, p;
        unsigned long long int  temp;
        for(int i=0; i<n; ++i)
            scanf("%llu", &temp), c.push_back(temp);
        for(int i=0; i<n; ++i)
            scanf("%llu", &temp), p.push_back(temp);
        sort(c.begin(), c.begin() + n);
        sort(p.begin(), p.begin() + n);
        reverse(p.begin(), p.begin() + n);
    /*
        for(int i=0;i<n;++i)
            cout<<c[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;++i)
            cout<<p[i]<<" ";
        cout<<endl;
    */
        unsigned long long int sum = 0;
        for(int i=0; i<n; ++i)
            sum += c[i] * p[i];
        printf("%llu\n", sum);
        scanf("%d", &n);
    }
    fclose(stdin);
    fclose(stdout);
}
