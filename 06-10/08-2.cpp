#include "../template.hpp"

map<string, int> display = {
    make_pair("abcefg", 0),
    make_pair("cf", 1),
    make_pair("acdeg", 2),
    make_pair("acdfg", 3),
    make_pair("bcdf", 4),
    make_pair("abdfg", 5),
    make_pair("abdefg", 6),
    make_pair("acf", 7),
    make_pair("abcdefg", 8),
    make_pair("abcdfg", 9)
};

string translate(string digit, map<char, char> & tr) {
    string ret;
    for (char c : digit) {
        ret += tr[c];
    }
    sort(all(ret));
    return ret;
}

int main() {
    string s;
    int sum = 0;
    while (cin >> s) {
        int num = 0;
        vector<string> digits;
        map<char, char> tr;
        set<char> one, seven, four;

        digits.pb(s);
        if (s.size() == 2) {
            one = set<char>(all(s));
        } else if (s.size() == 3) {
            seven = set<char>(all(s));
        } else if (s.size() == 4) {
            four = set<char>(all(s));
        }
        rep(i,0,9) {
            cin >> s;
            digits.pb(s);
            if (s.size() == 2) {
                one = set<char>(all(s));
            } else if (s.size() == 3) {
                seven = set<char>(all(s));
            } else if (s.size() == 4) {
                four = set<char>(all(s));
            }
        }
        cin >> s;

        rep(i,0,7) {
            char c = 'a'+i;
            int cnt = 0;
            for (string t : digits) {
                if (t.find(c) != string::npos) {
                    ++cnt;
                }
            }
            switch (cnt) {
                case 4:
                    tr[c] = 'e';
                    break;
                case 6:
                    tr[c] = 'b';
                    break;
                case 7:
                    if (four.count(c)) {
                        tr[c] = 'd';
                    } else {
                        tr[c] = 'g';
                    }
                    break;
                case 8:
                    if (one.count(c) == 0 && seven.count(c) == 1) {
                        tr[c] = 'a';
                    } else {
                        tr[c] = 'c';
                    }
                    break;
                case 9:
                    tr[c] = 'f';
                    break;
            }
        }

        rep (i,0,4) {
            cin >> s;
            num *= 10;
            num += display[translate(s, tr)];
        }
        sum += num;
    }
    cout << sum;
}
