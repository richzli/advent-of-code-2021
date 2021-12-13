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

    cin >> s; // fold
    cin >> s; // along
    cin >> s;

    int pos = s.find("=");
    char c = s[0];
    int ln = stoi(s.substr(pos+1, sz(s)-(pos+1)));

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
        ans.insert(p);
    }

    cout << sz(ans);
}
