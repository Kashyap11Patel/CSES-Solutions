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
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    int cycle_start = -1, cycle_end = -1;
    vector<bool> vis(n);
    vector<int> par(n);

    function<bool(int, int)> dfs;
    dfs = [&](int v, int p) {
        vis[v] = true;
        bool ans = false;
        for (auto c : g[v]) {
            if (c == p) continue;
            if (vis[c]) {
                cycle_start = c;
                cycle_end = v;
                return true;
            }
            par[c] = v;
            ans |= dfs(c, v);
            if (ans) return ans;
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, i)) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ans;
    ans.push_back(cycle_start);
    for (int it = cycle_end; it != cycle_start; it = par[it]) {
        ans.push_back(it);
    }
    ans.push_back(cycle_start);

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i + 1 << ' ';
    cout << '\n';
}