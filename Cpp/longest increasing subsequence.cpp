#include<bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)
#define show(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;
using namespace std;


int main(){
    int n;
    cin >> n;
    set<int> s;
    set<int> ::iterator it, it2;
    vector<int> v;
    for(int i=0, temp; i<n; ++i)
        cin >> temp, v.push_back(temp);
    for(int i=0; i<n; ++i){
        if(s.find(v[i])==s.end()){
            s.insert(v[i]);
            it = s.find(v[i]);
            it++;
            if(it!=s.end())
                s.erase(it);
        }

    }
    cout << s.size() <<endl;
}

/*
int main() {
	int n;
	//ios::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n+1, 1000000000);
	for (int i = 0; i < n; i++) {
		*upper_bound(d.begin(), d.end(), a[i]) = a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (d[i] == 1000000000) {
			cout << i << endl;
			return 0;
		}
	}
}
*/
