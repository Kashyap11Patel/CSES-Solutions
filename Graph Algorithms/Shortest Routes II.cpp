/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

#define INF 9e18


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dis(n + 1, vector<long long>(n + 1, 9e18));

    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] != INF && dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == INF) dis[a][b] = -1;
        cout << dis[a][b] << '\n';
    }
}