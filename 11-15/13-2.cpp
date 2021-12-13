#include "../template.hpp"

int main() {
    set<pii> points;
    string s;
    cin >> s;
    while (s != "---") {
        int pos = s.find(",");
        int i = stoi(s.substr(0, pos));
        int j = stoi(s.substr(pos+1, sz(s)-(pos+1)));

        points.insert({i,j});

        cin >> s;
    }

    int mxx, mxy, mnx, mny;

    while (cin >> s) { // fold
        cin >> s; // along
        cin >> s;

        int pos = s.find("=");
        char c = s[0];
        int ln = stoi(s.substr(pos+1, sz(s)-(pos+1)));

        mxx = 0, mxy = 0, mnx = 100000, mny = 100000;

        set<pii> ans;
        for (pii p : points) {
            if (c == 'y') {
                if (p.second > ln) {
                    p.second = 2*ln - p.second;
                }
            } else if (c == 'x') {
                if (p.first > ln) {
                    p.first = 2*ln - p.first;
                }
            }
            mxx = max(mxx, p.first);
            mxy = max(mxy, p.second);
            mnx = min(mnx, p.first);
            mny = min(mny, p.second);
            ans.insert(p);
        }
        points = ans;
    }

    vector<vector<char>> grid(mxy-mny+1, vector<char>(mxx-mnx+1, ' '));

    for (pii p : points) {
        grid[p.second-mny][p.first-mnx] = '#';
    }

    for (auto r : grid) {
        for (auto ch : r) {
            cout << ch;
        }
        cout << endl;
    }
}
