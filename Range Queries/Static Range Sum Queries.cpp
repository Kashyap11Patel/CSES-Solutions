/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, Q;
    cin >> n >> Q;

    vector<long long> prefix(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }
    // TC : O(n)
    // SC : O(n)
}