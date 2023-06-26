/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

bool bfs_shortest_path(int n, int m, vector<vector<char>>& input, int x, int y, vector<char>& path) {
    bool ans = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    parent[x][y] = make_pair(x, y);
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};
    int xb, yb;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int newx, newy;
        int X = p.first, Y = p.second;
        input[X][Y] = '#';
        for (int i = 0; i < 4; i++) {
            newx = X + dirx[i];
            newy = Y + diry[i];
            if (newx >= n || newx < 0 || newy >= m || newy < 0) continue;
            if (input[newx][newy] == '#') continue;
            q.push(make_pair(newx, newy));
            parent[newx][newy] = make_pair(X, Y);
            if (input[newx][newy] == 'B') {
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

    // TC : O(n*m);
    // SC : O(n*m);
}