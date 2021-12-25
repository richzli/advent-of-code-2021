#include "../template.hpp"

int n, m;

vector<vector<char>> play(vector<vector<char>> grid) {
    vector<vector<char>> new_grid(n, vector<char>(m, '.'));
    rep(i,0,n) {
        rep(j,0,m) {
            int k;
            switch (grid[i][j]) {
                case '.':
                    k = -1; break;
                case 'v':
                    k = 0; break;
                case '>':
                    k = 1; break;
            }
            if (k == 0) {
                new_grid[i][j] = grid[i][j];
                continue;
            }
            if (k == -1) {
                continue;
            }
            int nx = i + dx4[k], ny = j + dy4[k];
            nx %= n;
            ny %= m;
            
            if (grid[nx][ny] == '.') {
                new_grid[nx][ny] = grid[i][j];
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }

    grid = new_grid;
    new_grid = vector<vector<char>>(n, vector<char>(m, '.'));

    rep(i,0,n) {
        rep(j,0,m) {
            int k;
            switch (grid[i][j]) {
                case '.':
                    k = -1; break;
                case 'v':
                    k = 0; break;
                case '>':
                    k = 1; break;
            }
            if (k == 1) {
                new_grid[i][j] = grid[i][j];
                continue;
            }
            if (k == -1) {
                continue;
            }
            

            int nx = i + dx4[k], ny = j + dy4[k];
            nx %= n;
            ny %= m;
            
            if (grid[nx][ny] == '.') {
                new_grid[nx][ny] = grid[i][j];
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }

    return new_grid;
}

int main() {
    vector<vector<char>> grid;
    string s;
    while (cin >> s) {
        grid.pb(vector<char>(all(s)));
    }
    n = sz(grid);
    m = sz(grid[0]);

    int count = 0;
    vector<vector<char>> new_grid;
    while ((new_grid = play(grid)) != grid) {
        ++count;
        grid = new_grid;
    }

    cout << count + 1;
}
