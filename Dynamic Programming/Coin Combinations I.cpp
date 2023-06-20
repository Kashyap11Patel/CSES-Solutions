/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M = 1e9 + 7;

	int n, x;
	cin >> n >> x;

	vector<int> coins(n), ways(x + 1);

	for (int i = 0; i < n; i++) cin >> coins[i];

	//base case
	ways[0] = 1;

	for (int sum = 1; sum <= x; sum++) {

		for (auto coin : coins)
			if (coin <= sum) {
				ways[sum] += ways[sum - coin];
				if (ways[sum] >= M) ways[sum] -= M;
			}

	}

	cout << ways[x];

	// TC : O(n * x)
	// SC : O(x)
}