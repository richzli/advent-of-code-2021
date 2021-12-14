#include "../template.hpp"

int main() {
    string inp;
    cin >> inp;

    map<string, string> rules;
    string s;
    while (cin >> s) {
        string c;
        cin >> c;
        cin >> c;
        rules[s] = c;
    }

    map<string, ll> pairs;
    rep(i,0,sz(inp)-1) {
        string sb = inp.substr(i, 2);
        pairs[sb]++;
    }

    rep(j,0,40) {
        map<string, ll> newp;
        for (auto p : pairs) {
            if (rules[p.first] != "") {
                newp[string(1, p.first[0]) + rules[p.first]] += p.second;
                newp[rules[p.first] + string(1, p.first[1])] += p.second;
            } else {
                newp[p.first] += p.second;
            }
        }
        pairs = newp;
    }

    vector<ll> chs(26);
    rep(i,0,26) {
        for (auto p : pairs) {
            if (p.first[0] == ('A'+i))
                chs[i] += p.second;
        }
    }

    chs[inp[sz(inp)-1]-'A']++;

    chs.erase(remove(all(chs), 0), chs.end());
    sort(all(chs));

    cout << (chs.back() - chs.front());
}
