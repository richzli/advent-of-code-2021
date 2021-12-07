#include "../template.hpp"

int main() {
    map<int, int> crabs;
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

    int best = numeric_limits<int>::max();
    rep(i, 0, maxx+1) {
        int score = 0;
        for (auto c : crabs) {
            score += abs(c.first-i) * c.second;
        }
        best = min(score, best);
    }

    cout << best;
}
