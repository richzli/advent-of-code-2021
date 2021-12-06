#include "../template.hpp"

int main() {
    map<int, vector<int>> fish;
    string s;
    cin >> s;
    int pos = 0, oldpos = 0;
    while ((pos = s.find(",", oldpos)) != string::npos) {
        int i = stoi(s.substr(oldpos, pos - oldpos));
        oldpos = pos + 1;
        fish[i].pb(7);
    }
    fish[stoi(s.substr(oldpos, s.size()-oldpos))].pb(7);

    rep(i,0,80) {
        map<int, vector<int>> newfish;
        for (int j : fish[0]) {
            newfish[j+1].pb(7);
            newfish[j-1].pb(j);
        }
        for (auto x : fish) {
            if (x.first != 0) {
                newfish[x.first-1].insert(newfish[x.first-1].end(), x.second.begin(), x.second.end());
            }
        }
        fish = newfish;
    }

    int sum = 0;
    for (auto x : fish) {
        sum += x.second.size();
    }
    cout << sum;
}
