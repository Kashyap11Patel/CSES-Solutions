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

    vector<int> ways(x + 1);

    ways[0] = 1;

    for (int i = 0; i < n; i++) {

        int coin;
        cin >> coin;

        for (int sum = coin; sum <= x; sum++) {
            ways[sum] += ways[sum - coin];
            if (ways[sum] >= M) ways[sum] -= M;
        }

    }

    cout << ways[x];

    // TC : O(n * x)
    // SC : O(x)
}