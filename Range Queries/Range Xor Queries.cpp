/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, Q;
    cin >> n >> Q;

    vector<vector<int>> prefix(n + 1, vector<int>(31));

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int bit = 0; bit < 31; bit++) {
            prefix[i][bit] = prefix[i - 1][bit] + (num >> bit & 1);
        }
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int bit = 0; bit < 31; bit++) {
            if ((prefix[b][bit] - prefix[a - 1][bit]) & 1) ans += (1LL << bit);
        }
        cout << ans << '\n';
    }
}