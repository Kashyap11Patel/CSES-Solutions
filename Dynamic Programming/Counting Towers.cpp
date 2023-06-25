/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

const int nax = 1e6 + 1;
int MOD = 1e9 + 7;
int dp[nax][2];

int add(long long a, long long b) {
    return (a + b) % MOD;
}

int mul(long long a, long long b) {
    return (a * b) % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // base case
    dp[1][0] = dp[1][1] = 1;

    for (int i = 2; i < nax; i++) {
        dp[i][0] = add(mul(dp[i - 1][0], 4), dp[i - 1][1]);
        dp[i][1] = add(mul(dp[i - 1][1], 2), dp[i - 1][0]);
    }

    int testCase;
    cin >> testCase;
    while (testCase--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }

    // TC : O(n)
    // SC : O(n)
}