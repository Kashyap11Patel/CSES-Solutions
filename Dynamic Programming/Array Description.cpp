/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MOD = (int)1e9 + 7;
    int n, m;
    cin >> n >> m;

    // dp[i][j] = number ways to end with jth number at ith
    // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 2][j + 2]

    int dp[m + 1] = {0};
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        int prev = dp[0], curr = dp[1], next = (m >= 2 ? dp[2] : 0);
        for (int j = 1; j <= m; j++) {
            if (val == 0 || val == j) {
                dp[j] = (i == 0 ? 1 : (prev + curr) % MOD + next) % MOD;
            } else {
                dp[j] = 0;
            }
            prev = curr;
            curr = next;
            next = (m >= j + 2 ? dp[j + 2] : 0);
        }
    }

    int ans = 0;
    for (int i : dp) ans = (ans + i) % MOD;

    cout << ans << '\n';
    // TC : O(n * m)
    // SC : O(m)
}