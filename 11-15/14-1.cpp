#include "../template.hpp"

int main() {
    string inp;
    cin >> inp;

    map<string, char> rules;
    string s;
    while (cin >> s) {
        string c;
        cin >> c;
        cin >> c;
        rules[s] = c[0];
    }

    rep(j,0,10) {
        string ans;
        rep(i,0,sz(inp)-1) {
            string sb = inp.substr(i, 2);
            ans.pb(sb[0]);
            ans.pb(rules[sb]);
        }
        ans.pb(inp[sz(inp)-1]);
        inp = ans;
    }

    map<char, int> chs;
    for (char c : inp) {
        chs[c]++;
    }

    int mx = 0, mn = sz(inp);
    for (auto p : chs) {
        mx = max(mx, p.second);
        mn = min(mn, p.second);
    }

    cout << (mx-mn);
}
