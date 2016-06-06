/// #sh

#include<bits/stdc++.h>

using namespace std;

#define lld long long int

int h[50000], c[50000];

const int MAXN = 50010;
const int MOD = 1000000007;

class FenwickTree
{
private:
	lld tree[MAXN];

public:
	FenwickTree(){
		memset(tree, 0, sizeof(tree));
	}

	lld get(int idx){
		return query(idx) - query(idx - 1);
	}

	void set(int idx, lld val){
		long long curr = get(idx);
		update(idx, val - curr);
	}

	void update(int idx, lld val)
	{
		while (idx <= MAXN)
		{
			tree[idx] = (tree[idx] + val) % MOD;
			idx += (idx & -idx);
		}
	}

	lld query(int idx){
		lld sum = 0;
		while (idx > 0){
			sum = (sum + tree[idx]) % MOD;
			idx -= (idx & -idx);
		}
		return sum;
	}
};

FenwickTree s[128];

int main()
{
	int n, k;
	cin >> n >> k;
	s[0].update(1, 1);

	for (int i = 0; i < n; i++){

		cin >> h[i] >> c[i];
		h[i]++;  c[i]--;

		for (int j = 0; j < (1 << k); j++){
			lld val = s[j].query(h[i] - 1);
			s[j | (1 << c[i])].update(h[i], val);
		}
	}
	cout << s[(1 << k) - 1].query(50001) << endl;
	return 0;
}

