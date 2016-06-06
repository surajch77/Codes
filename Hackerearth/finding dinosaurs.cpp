/// #sh

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, k, l, q;
    cin >> n >> k >> l >> q;
    string wa = "You cant fool me :P";
    if(k==1){
        map<int, string> m;
        for(int i=0; i<n; ++i){
            string name;
            cin >> name;
            int val;
            cin >> val;
            m[val] = name;
        }

        while(q--){
            int val;
            cin >> val;
            if(m.find(val) != m.end())
                cout << m[val] <<"\n";
            else
                cout << wa << "\n";
        }
    }
    else if(k==2){
        map<pair<int, int>, string> m;
        for(int i=0; i<n; ++i){
            string name;
            cin >> name;
            pair<int, int> temp;
            cin >> temp.first >> temp.second;
            m[temp] = name;
        }

        while(q--){
            pair<int, int> val;
            cin >> val.first >> val.second;
            if(m.find(val) != m.end())
                cout << m[val] <<"\n";
            else
                cout << wa << "\n";
        }
    }

    else if(k==3){
        map<pair<int, pair<int, int> >, string> m;
        for(int i=0; i<n; ++i){
            string name;
            cin >> name;
            pair<int, pair<int, int> > temp;
            cin >> temp.first >> temp.second.first >> temp.second.second;
            m[temp] = name;
        }

        while(q--){
            pair<int, pair<int, int> >val;
            cin >> val.first >> val.second.first >> val.second.second;
            if(m.find(val) != m.end())
                cout << m[val] <<"\n";
            else
                cout << wa << "\n";
        }
    }
    else if(k==4){
        map<pair<int, pair<int, pair<int, int> > >, string> m;
        for(int i=0; i<n; ++i){
            string name;
            cin >> name;
            pair<int, pair<int, pair<int, int> > > temp;
            cin >> temp.first >> temp.second.first >> temp.second.second.first >> temp.second.second.second;
            m[temp] = name;
        }
        while(q--){
            pair<int, pair<int, pair<int, int> > > temp;
            cin >> temp.first >> temp.second.first >> temp.second.second.first >> temp.second.second.second;
            if(m.find(temp) != m.end())
                cout << m[temp] <<"\n";
            else
                cout << wa << "\n";
        }

    }
    else{
        map<pair<int, pair<int, pair<int, pair<int, int> > > >, string> m;
        for(int i=0; i<n; ++i){
            pair<int, pair<int, pair<int, pair<int, int> > > > temp;
            string name;
            cin >> name;
            cin >> temp.first >> temp.second.first >> temp.second.second.first >> temp.second.second.second.first >> temp.second.second.second.second;
            m[temp] = name;
        }
        while(q--){
            pair<int, pair<int, pair<int, pair<int, int> > > > temp;
            cin >> temp.first >> temp.second.first >> temp.second.second.first >> temp.second.second.second.first >> temp.second.second.second.second;
            if(m.find(temp) != m.end())
                cout << m[temp] <<"\n";
            else
                cout << wa << "\n";
        }
    }


}
