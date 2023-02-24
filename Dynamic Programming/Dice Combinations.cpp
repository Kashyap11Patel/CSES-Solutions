/** kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;


//dp[i] denotes number of ways to make sum i

long long mod = (int)1e9 + 7;

int main() {
	int n; cin >> n;
	vector<long long> dp(n + 1);

	//base case
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++)
			if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % (mod);

	cout << dp[n] << endl;

	// TC : O(6n)
	// SC : O(n)
}
