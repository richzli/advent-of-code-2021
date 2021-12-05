#include "../template.hpp"

int main() {
    vector<vi> vents;
    string s;
    while (cin >> s) {
        vi vent;
        int idx = s.find(",");
        vent.pb(stoi(s.substr(0, idx)));
        vent.pb(stoi(s.substr(idx+1, s.length() - (idx + 1))));
        cin >> s;
        cin >> s;
        idx = s.find(",");
        vent.pb(stoi(s.substr(0, idx)));
        vent.pb(stoi(s.substr(idx+1, s.length() - (idx + 1))));
        vents.pb(vent);
    }

    vector<vi> grid(1000, vi(1000, 0));
    for (vi v : vents) {
        if (v[0] == v[2]) {
            rep(i, min(v[1], v[3]), max(v[1], v[3]) + 1) {
                grid[v[0]][i]++;
            }
        } else if (v[1] == v[3]) {
            rep(i, min(v[0], v[2]), max(v[0], v[2]) + 1) {
                grid[i][v[1]]++;
            }
        } else {
            rep(i, 0, abs(v[0]-v[2]) + 1) {
                if ((v[0] < v[2]) == (v[1] < v[3])) {
                    grid[min(v[0], v[2]) + i][min(v[1], v[3]) + i]++;
                } else {
                    grid[min(v[0], v[2]) + i][max(v[1], v[3]) - i]++;
                }
            }
        }
    }

    int sum = 0;
    rep(i,0,1000) {
        rep(j,0,1000) {
            if (grid[i][j] > 1) {
                ++sum;
            }
        }
    }

    cout << sum;
}
