/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

void bfs_shortest_path(int n, vector<int> adj[]) {
    queue<int> q;
    vector<int> parent(n + 1);
    vector<int> used(n + 1);
    used[1] = 1;
    parent[1] = 1;
    q.push(1);
    bool ans = 0;
    while (!q.empty()) {
        int com = q.front();
        q.pop();
        for (auto child : adj[com]) {
            if (!used[child]) {
                used[child] = 1;
                parent[child] = com;
                q.push(child);
                if (child == n) {
                    ans = 1;
                    break;
                }
            }
        }
        if (ans) break;
    }
    if (!ans) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    path.push_back(n);
    int x = n;
    while (parent[x] != x) {
        path.push_back(parent[x]);
        x = parent[x];
    }
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (auto i : path) {
        cout << i << " ";
    }
}

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

    vector<int> vis(n);

    function <bool(int)> dfs;
    dfs = [&] (int v) {
        bool ans = true;
        for (int c : g[v]) {
            if (!vis[c]) {
                vis[c] = (vis[v] ^ 1 ^ 2);
                ans &= dfs(c);
            } else {
                if (vis[c] == vis[v]) return false;
            }
        }
        return ans;
    };

    bool isPoss = true;
    for (int i = 0; i < n && isPoss; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            isPoss &= dfs(i);
        }
    }

    if (isPoss) {
        for (auto i : vis) cout << i << ' ';
    } else {
        cout << "IMPOSSIBLE";
    }
    // TC : O(n + m);
    // SC : O(n + m);
}