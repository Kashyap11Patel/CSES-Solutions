/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, long long>>>& g) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push(make_pair(0,  start));

    vector<long long> distance(g.size(), -1);
    while (q.size()) {
        auto p = q.top();
        q.pop();

        if (distance[p.second] != -1) continue;

        distance[p.second] = p.first;

        for (auto c : g[p.second])
            if (distance[c.first] == -1 || distance[c.first] > p.first + c.second)
                q.push(make_pair(p.first + c.second, c.first));
    }

    for (auto i : distance) cout << i << ' ';
    cout << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].push_back(make_pair(b, c));
    }

    dijkstra(0, g);
}