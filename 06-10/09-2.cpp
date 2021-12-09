#include "../template.hpp"

#define bound(x, y) ((0 <= (x)) && (0 <= (y)) && ((x) < n) && ((y) < m))
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
#define val(c) (c - '0')

ll dfs(int x, int y, vector<vi> & grid, vector<vi> & visited) {
    visited[x][y] = 1;
    int sum = 1;
    rep(k,0,4) {
        int nx = x + dx[k], ny = y + dy[k];
        if (bound(nx, ny) && (grid[nx][ny] > grid[x][y]) && visited[nx][ny] == 0 && (val(grid[nx][ny]) != 9)) {
            sum += dfs(nx, ny, grid, visited);
        }
    }
    return sum;
}

int main() {
    vector<vi> grid;
    string s;
    while (cin >> s) {
        grid.pb(vi(all(s)));
    }

    n = sz(grid), m = sz(grid[0]);
    vector<vi> visited(n, vi(m));

    vector<pii> lows;

    rep(i,0,sz(grid)) {
        rep(j,0,sz(grid[i])) {
            bool yes = true;
            rep(k,0,4) {
                int nx = i + dx[k], ny = j + dy[k];
                if (bound(nx, ny) && grid[nx][ny] <= grid[i][j]) {
                    yes = false;
                }
            }
            if (yes) {
                lows.pb({i, j});
            }
        }
    }

    vector<ll> szs;
    for (pii low : lows) {
        szs.pb(dfs(low.first, low.second, grid, visited));
    }
    sort(all(szs), greater<int>());

    cout << szs[0] * szs[1] * szs[2];
}
