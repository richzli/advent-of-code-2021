#include "../template.hpp"

#define bound(x, y) ((0 <= (x)) && (0 <= (y)) && ((x) < n) && ((y) < m))
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    vector<vi> grid;
    string s;
    while (cin >> s) {
        grid.pb(vi(all(s)));
    }

    int n = sz(grid), m = sz(grid[0]);

    int sum = 0;
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
                sum += grid[i][j] - '0' + 1;
            }
        }
    }

    cout << sum;
}
