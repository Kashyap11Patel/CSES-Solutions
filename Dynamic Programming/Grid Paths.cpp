/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M = (int)1e9 + 7;

    int n;
    cin >> n;


    char grid[n][n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // dp[x][y] = number of ways to reach (x, y)

    vector<vector<int>> dp(n, vector<int>(n));

    //base case
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1 && grid[i][j + 1] != '*') {
                dp[i][j + 1] += dp[i][j];
                if (dp[i][j + 1] >= M) dp[i][j + 1] -= M;
            }
            if (i != n - 1 && grid[i + 1][j] != '*') {
                dp[i + 1][j] += dp[i][j];
                if (dp[i + 1][j] >= M) dp[i + 1][j] -= M;
            }
        }
    }

    cout << dp[n - 1][n - 1];
    // TC : O(n * n)
    // SC : O(n * n)
}