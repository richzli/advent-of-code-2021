#include "../template.hpp"

int main() {
    vector<int> zero, one;
    int count;
    string s;
    vector<string> ss;
    while (cin >> s) {
        ss.pb(s);
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
        ++count;
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

    vi ozero(s.size()), oone(s.size());
    vi oxygen(count, 1), co2(count, 1);
    int oc = count, cc = count;
    for (int i = 0; i < zero.size(); ++i) {
        zero[i] = 0; one[i] = 0;
        for (int j = 0; j < count; ++j) {
            if (ss[j][i] == '1') {
                if (oxygen[j] == 1) {
                    oone[i]++;
                }
                if (co2[j] == 1) {
                    one[i]++;
                }
            } else {
                if (oxygen[j] == 1) {
                    ozero[i]++;
                }
                if (co2[j] == 1) {
                    zero[i]++;
                }
            }
        }
        for (int j = 0; j < count; ++j) {
            if (oc > 1 && ss[j][i] == '1' && oxygen[j] == 1 && (ozero[i] > oone[i])) {
                oxygen[j] = 0;
                --oc;
            }
            if (cc > 1 && ss[j][i] == '0' && co2[j] == 1 && (zero[i] > one[i])) {
                co2[j] = 0;
                --cc;
            }
            if (oc > 1 && ss[j][i] == '0' && oxygen[j] == 1 && (ozero[i] <= oone[i])) {
                oxygen[j] = 0;
                --oc;
            }
            if (cc > 1 && ss[j][i] == '1' && co2[j] == 1 && (zero[i] <= one[i])) {
                co2[j] = 0;
                --cc;
            }
        }
    }

    int oval = 0, cval = 0;
    for (int i = 0; i < count; ++i) {
        if (oxygen[i] == 1) {
            oval = stoi(ss[i], 0, 2);
        }
        if (co2[i] == 1) {
            cval = stoi(ss[i], 0, 2);
        }
    }

    cout << oval * cval;
}
