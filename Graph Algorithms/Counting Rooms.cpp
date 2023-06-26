/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    function <void(int, int)> dfs;

    dfs = [&] (int x, int y) {
        v[x][y] = '#';
        if (x + 1 < n && v[x + 1][y] == '.')  dfs(x + 1, y);
        if (y + 1 < m && v[x][y + 1] == '.')  dfs(x, y + 1);
        if (x - 1 >= 0 && v[x - 1][y] == '.') dfs(x - 1, y);
        if (y - 1 >= 0 && v[x][y - 1] == '.') dfs(x, y - 1);
    };

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') rooms++, dfs(i, j);
        }
    }

    cout << rooms;

    // TC : O(n*m);
    // SC : O(n*m);
}