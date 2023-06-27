/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

bool bfs_shortest_path(int n, int m, vector<vector<char>>& input, int x, int y, vector<char>& path) {
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        return 1;
    }
    vector<vector<int>> nin(n, vector<int>(m, 1e7));
    queue<pair<pair<int, int>, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == 'M') {
                nin[i][j] = 0;
                Q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        for (int i = 0, n_x, n_y; i < 4; i++) {
            n_x = p.first.first + dirx[i];
            n_y = p.first.second + diry[i];
            if (n_x >= n || n_x < 0 || n_y >= m || n_y < 0) continue;
            if (input[n_x][n_y] == '#' || nin[n_x][n_y] != 1e7) continue;
            nin[n_x][n_y] = p.second + 1;
            Q.push(make_pair(make_pair(n_x, n_y), p.second + 1));
        }
    }
    bool ans = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x, y), 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    parent[x][y] = make_pair(x, y);
    int xb, yb;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int newx, newy;
        int X = p.first.first, Y = p.first.second;
        input[X][Y] = '#';
        for (int i = 0; i < 4; i++) {
            newx = X + dirx[i];
            newy = Y + diry[i];
            if (newx >= n || newx < 0 || newy >= m || newy < 0) continue;
            if (input[newx][newy] == '#' || input[newx][newy] == 'M' || nin[newx][newy] <= p.second + 1) continue;
            q.push(make_pair(make_pair(newx, newy), p.second + 1));
            parent[newx][newy] = make_pair(X, Y);
            if (newx == 0 || newx == n - 1 || newy == 0 || newy == m - 1) {
                xb = newx;
                yb = newy;
                ans = 1;
                break;
            }
            input[newx][newy] = '#';
        }
        if (ans)break;
    }
    if (ans == 0)
        return ans;
    x = parent[xb][yb].first;
    y = parent[xb][yb].second;
    while (make_pair(x, y) != make_pair(xb, yb)) {
        if (x == xb) {
            if (y - yb == 1) path.push_back('L');
            else path.push_back('R');
        } else {
            if (x - xb == 1) path.push_back('U');
            else path.push_back('D');
        }
        xb = x;
        yb = y;
        x = parent[xb][yb].first;
        y = parent[xb][yb].second;
    }
    reverse(path.begin(), path.end());
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    int x, y;
    vector<vector<char>> input(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
            if (input[i][j] == 'A') {
                x = i; y = j;
            }
        }
    }
    vector<char> path;
    bool ans = bfs_shortest_path(n, m, input, x, y, path);
    if (ans) {
        cout << "YES" << endl << path.size() << endl;
        for (auto i : path) cout << i;
        cout << endl;
    } else {
        cout << "NO" << endl;
    }


}