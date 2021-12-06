#include "../template.hpp"

int main() {
    map<int, ll> fish;
    string s;
    cin >> s;
    int pos = 0, oldpos = 0;
    while ((pos = s.find(",", oldpos)) != string::npos) {
        int i = stoi(s.substr(oldpos, pos - oldpos));
        oldpos = pos + 1;
        fish[i]++;
    }
    fish[stoi(s.substr(oldpos, s.size()-oldpos))]++;

    rep(i,0,256) {
        map<int, ll> newfish;
        newfish[6] += fish[0];
        newfish[8] += fish[0];
        for (auto x : fish) {
            if (x.first != 0) {
                newfish[x.first - 1] += fish[x.first];
            }
        }
        fish = newfish;
    }

    ll sum = 0;
    for (auto x : fish) {
        sum += x.second;
    }
    cout << sum;
}
