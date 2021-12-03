#include "../template.hpp"

int main() {
    vector<int> zero, one;
    string s;
    while (cin >> s) {
        if (zero.size() == 0) {
            zero = vi(s.size());
            one = vi(s.size());
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                zero[i] += 1;
            } else {
                one[i] += 1;
            }
        }
    }

    int gamma = 0, eps = 0;
    for (int i = 0; i < zero.size(); ++i) {
        gamma <<= 1;
        eps <<= 1;
        if (zero[i] > one[i]) {
            eps += 1;
        } else {
            gamma += 1;
        }
    }

    cout << gamma * eps;
}
