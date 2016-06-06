// C++ program to find longest contiguous subsequence
#include<bits/stdc++.h>
using namespace std;

// Returns length of the longest contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
	unordered_set<int> S;
	int ans = 0;

	// Hash all the array elements
	for (int i = 0; i < n; i++)
		S.insert(arr[i]);

	// check each possible sequence from the start
	// then update optimal length
    unordered_set<int>::iterator it;
    for(it = S.begin();it!=S.end();++it)
        cout<<*it<<" ";
    cout<<endl;
    //cout<<S.end()<<endl;
	for (int i=0; i<n; i++)
	{
		// if current element is the starting
		// element of a sequence
		if (S.find(arr[i]-1) == S.end())
		{
			// Then check for next elements in the
			// sequence
			int j = arr[i];
			while (S.find(j) != S.end())
				j++;

			// update optimal length if this length
			// is more
			ans = max(ans, j - arr[i]);
			cout<<ans<<endl;
		}
	}
	return ans;
}

// Driver program
int main()
{
	int arr[] = {1, 9, 3, 10, 4, 20, 2};
	int n = sizeof arr/ sizeof arr[0];
	cout << "Length of the Longest contiguous subsequence is "
		<< findLongestConseqSubseq(arr, n);
	return 0;
}
