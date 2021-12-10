#include "../template.hpp"

int main() {
    string s;
    vector<ll> anss;
    while (cin >> s) {
        stack<char> stk;
        bool fail = false;
        for (char c : s) {
            switch (c) {
                case '{':
                case '[':
                case '(':
                case '<':
                    stk.push(c);
                    break;
                default:
                    if (!stk.empty()) {
                        switch (c) {
                            case ')':
                                if (stk.top() != '(') fail = true;
                                break;
                            case ']':
                                if (stk.top() != '[') fail = true;
                                break;
                            case '}':
                                if (stk.top() != '{') fail = true;
                                break;
                            case '>':
                                if (stk.top() != '<') fail = true;
                                break;
                        }
                        stk.pop();
                    }
            }
            if (fail) break;
        }

        ll score = 0;
        if (!fail) {
            while (!stk.empty()) {
                score *= 5;
                switch (stk.top()) {
                    case '(':
                        score += 1;
                        break;
                    case '[':
                        score += 2;
                        break;
                    case '{':
                        score += 3;
                        break;
                    case '<':
                        score += 4;
                        break;
                }
                stk.pop();
            }
            anss.pb(score);
        }
    }

    sort(all(anss));
    cout << anss[sz(anss)/2];
}
