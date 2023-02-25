/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

// here we use bottom up dp approch
// the problem is based on knapsack problem

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x; cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, INT_MAX);

    // base case
    dp[0] = 0;
    for (int c = 0; c < n; c++)
        for (int sum = coins[c]; sum <= x; sum++)
            if (dp[sum - coins[c]] != INT_MAX)
                dp[sum] = min(dp[sum], dp[sum - coins[c]] + 1);


    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;

    // TC : O(n * x)
    // SC : O(x)
}