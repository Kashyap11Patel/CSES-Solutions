/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> g[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n);

    function<void(int)> dfs;
    dfs = [&](int v) {
        vis[v] = true;
        for (auto c : g[v])
            if (!vis[c]) dfs(c);
    };

    int cnt = 0;
    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            nodes.push_back(i + 1);
            cnt++;
            dfs(i);
        }
    }

    cout << (int)nodes.size() - 1 << '\n';

    for (int i = 1; i < (int)nodes.size(); i++) {
        cout << nodes[i - 1] << ' ' << nodes[i] << '\n';
    }
    // TC : O(n + m);
    // SC : O(n + m);
}