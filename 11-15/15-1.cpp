#include "../template.hpp"

#define val(c) (c - '0')

int main() {
    vector<vi> grid;
    string s;
    while (cin >> s) {
        grid.pb(vi(all(s)));
    }

    int n = sz(grid), m = sz(grid[0]);
    vector<vi> risk(sz(grid), vi(sz(grid[0]), numeric_limits<int>::max()));

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();

        int i = top.second.first, j = top.second.second;
        int v = top.first;

        if (risk[i][j] == numeric_limits<int>::max()) {
            risk[i][j] = v;
            
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx4[k], ny = j + dy4[k];
                if (bound(nx, ny)) {
                    pq.push({v + val(grid[nx][ny]), {nx, ny}});
                }
            }
        }
    }

    cout << risk[n-1][m-1];
}

