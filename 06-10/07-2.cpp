#include "../template.hpp"

int main() {
    map<int, ll> crabs;
    string s;
    cin >> s;
    int pos = 0, oldpos = 0;
    int maxx = -1;
    while ((pos = s.find(",", oldpos)) != string::npos) {
        int i = stoi(s.substr(oldpos, pos - oldpos));
        oldpos = pos + 1;
        crabs[i]++;
        maxx = max(maxx, i);
    }
    crabs[stoi(s.substr(oldpos, s.size()-oldpos))]++;

    ll best = numeric_limits<ll>::max();
    rep(i, 0, maxx+1) {
        ll score = 0;
        for (auto c : crabs) {
            score += (abs(c.first-i) * (abs(c.first-i)+1))/2 * c.second;
        }
        best = min(score, best);
    }

    cout << best;
}
