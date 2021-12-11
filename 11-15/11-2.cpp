#include "../template.hpp"

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0}, dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int n, m;
vector<vi> g;

int sim() {
    int cnt = 0;

    queue<pii> q;
    rep(i,0,n) {
        rep(j,0,m) {
            ++g[i][j];
            if (g[i][j] > 9) {
                q.push({i,j});
            }
        }
    }

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int i = p.first, j = p.second;
        if (g[i][j] > 9) {
            g[i][j] = 0;
            ++cnt;
            rep(k,0,8) {
                int nx = i + dx[k], ny = j + dy[k];
                if (bound(nx, ny) && g[nx][ny] > 0) {
                    ++g[nx][ny];
                    if (g[nx][ny] > 9) {
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

    return cnt;
}

int main() {
    string s;
    while (cin >> s) {
        g.pb(vi());
        for (char c : s) {
            g.back().pb(c-'0');
        }
    }

    int count = 0;
    n = g.size();
    m = g[0].size();
    while (true) {
        count++;
        if (sim() == (n*m)) break;
        
    }
    cout << count;
}
